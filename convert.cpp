/*
This file is part of kynnaugh-cc.

Kynnaugh-cc is free software: you can redistribute it and/or modify
it under the terms of the Apache License, version 2.0 as published by
the Apache Software Foundation, either version 2 of the License, or
(at your option) any later version.

Kynnaugh-cc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
Apache License, version 2.0 for more details.

You should have received a copy of the Apache License, version 2.0
along with kynnaugh-cc.  If not, see <https://www.apache.org/licenses/LICENSE-2.0>.
*/

#include "convert.h"

#include "libresample/libresample.h"
#include "sndfile/sndfile.h"
#include "dbg.h"

convert::convert()
    : QObject(nullptr)
{}

//Static function forward declarations
static sf_count_t vio_get_filelen(void *userdata);
static sf_count_t vio_read(void *ptr, sf_count_t count, void *userdata);
static sf_count_t vio_write(const void *ptr, sf_count_t count, void *userdata);
static sf_count_t vio_seek(sf_count_t offset, int whence, void *userdata);
static sf_count_t vio_tell(void *userdata);
static sf_count_t toFloatMono(QBuffer *dat, qint32 channes, float **retval);
static void logErrors(SNDFILE *hnd);

class lazydata
{
public:
    QBuffer *dat;    //Required to be initialized.
    qint64 samplesize;  //Number of bytes per 1-channel sample.
    qint64 channels; //Must be 1 or 2 (we don't handle multi-channel).
};

//Assume `dat` contains Signed 16-bit LE PCM samples at 48 kHz
//Returns a FLAC file with Signed 16-bit LE samples at 16 kHz.
QBuffer *convert::convertRawToFlac(QBuffer *dat, qint32 channes)
{
    if(dat == nullptr || dat->size() == 0)
    {
        dbg::qStdOut() << "convert::convertRawToFlac got a NULL or 0-size QBuffer!\n";
        return nullptr;
    }

    dbg::qStdOut() << "convert::convertRawToFlac got a " << channes << " channel PCM QBuffer with " << dat->size() << " bytes\n";

    dbg::writeToFile(dat, "-s16le-48k-orig.raw");

    //short to float and (possibly) stereo to mono conversion step
    float *monoSamples;
    int numMonoSamples = toFloatMono(dat, channes, &monoSamples);

    dbg::writeToFile((char*)monoSamples, numMonoSamples*4, "-float-48k.raw");

    dbg::qStdOut() << "convert::convertRawToFlac: done toFloatMono and we got " << numMonoSamples << " samples.\n";

    //Resample from 48 kHz to 16 kHz
    int inBufferUsed = 0;
    void *resampler = resample_open(1, 0.01, 8);
    float *outBuffer = new float[numMonoSamples * 4]; //Waste lots of memory for fun and profit; why not?
    int outBufferUsed = resample_process(resampler, 1.0 / 3.0, monoSamples, numMonoSamples, true, &inBufferUsed, outBuffer, numMonoSamples * 4);

    dbg::writeToFile((char*)outBuffer, outBufferUsed*4, "-float-16k.raw");

    dbg::qStdOut() << "convert::convertRawToFlac: done libresample part and it generated " << outBufferUsed << " samples in the outbuffer\n";
    dbg::qStdOut() << "convert::convertRawToFlac: numMonoSamples/outBufferUsed=" << ((double)((double)numMonoSamples)/((double)outBufferUsed)) << "\n";


    //Encode in FLAC!
    QBuffer *outbuf = new QBuffer();
    lazydata laz;
    outbuf->open(QIODevice::WriteOnly);
    laz.channels = 1;
    laz.dat = outbuf;
    laz.samplesize = 2;


    SF_INFO sfi;
    sfi.channels = 1;
    sfi.format = SF_FORMAT_FLAC | SF_FORMAT_PCM_16;
    sfi.samplerate = 16000;
    sfi.frames = 0;
    sfi.sections = 1;
    sfi.seekable = 1;
    if(!sf_format_check(&sfi))
    {
        dbg::qStdOut() << "sf_format_check() failed!\n";
    }

    SF_VIRTUAL_IO virt;
    virt.get_filelen = &vio_get_filelen;
    virt.read = &vio_read;
    virt.write = &vio_write;
    virt.seek = &vio_seek;
    virt.tell = &vio_tell;

    SNDFILE *hnd = sf_open_virtual(&virt, SFM_WRITE, &sfi, static_cast<void*>(&laz));
    logErrors(hnd);
    sf_count_t writsize = sf_write_float(hnd, outBuffer, outBufferUsed);
    logErrors(hnd);
    dbg::qStdOut() << "sf_write_float() returned\n";
    sf_close(hnd);
    hnd = nullptr;
    dbg::qStdOut() << "sf_close() of the SFM_WRITE handle completed! Wrote " << QString::number(writsize) << " samples into the FLAC encoder.\n";
    logErrors(hnd);

    delete[] outBuffer;

    dbg::qStdOut() << "convert::convertRawToFlac: returning outbuf with size " << QString::number(outbuf->size()) << " bytes." << "\n";

    dbg::writeToFile(outbuf, ".flac");

    return outbuf;
}

static void logErrors(SNDFILE *hnd)
{
    int errnumber = sf_error(hnd);
    if(errnumber != SF_ERR_NO_ERROR)
    {
        dbg::qStdOut() << "libsndfile Error #" << errnumber << ": " << sf_strerror(hnd) << "\n";
    }
}

static sf_count_t toFloatMono(QBuffer *dat, qint32 channes, float **retval)
{
    if(!dat->isOpen())
    {
        dat->open(QIODevice::ReadOnly);
    }
    dat->seek(0);

    SF_INFO origInfo;
    origInfo.channels = channes;
    origInfo.format = SF_FORMAT_RAW | SF_FORMAT_PCM_16 | SF_ENDIAN_LITTLE;
    origInfo.samplerate = 48000;
    origInfo.frames = 0;
    origInfo.sections = 1;
    origInfo.seekable = 1;

    SF_VIRTUAL_IO virt;
    virt.get_filelen = &vio_get_filelen;
    virt.read = &vio_read;
    virt.write = &vio_write;
    virt.seek = &vio_seek;
    virt.tell = &vio_tell;

    lazydata olazydat;
    olazydat.channels = channes;
    olazydat.dat = dat;
    olazydat.samplesize = 2;

    //Open a virtual I/O device passing our function pointers.
    SNDFILE *orighandle = sf_open_virtual(&virt, SFM_READ, &origInfo, static_cast<void*>(&olazydat));
    logErrors(orighandle);

    dbg::qStdOut() << "convert::toFloatMono(): SNDFILE sees " << origInfo.frames << " frames from original QBuffer.\n";

    //Create a buffer to store the original data in float format, and read it out from sndfile.
    float *audioIn = new float[origInfo.channels * origInfo.frames];
    sf_count_t numReadSamples = sf_readf_float(orighandle, audioIn, origInfo.frames);
    logErrors(orighandle);

    //If we're already mono, don't copy; otherwise, allocate the output buffer for downmixing
    float *audioOut = (channes > 1 ? new float[origInfo.frames] : audioIn);

    //Here we take the average of each channel's samples as a linear downmixing algorithm.
    if(channes > 1)
    {
        for(int i = 0; i < origInfo.frames; i++)
        {
            audioOut[i] = 0;
            for(int j = 0; j < origInfo.channels; j++)
                audioOut[i] += audioIn[i*origInfo.channels + j];
            audioOut[i] /= origInfo.channels;
        }
    }
    sf_close(orighandle);
    orighandle = nullptr;
    logErrors(orighandle);

    //If the orig was stereo, audioOut is a different buffer, we can discard the original input
    if(channes > 1)
    {
        delete[] audioIn;
    }

    *retval = audioOut;

    return numReadSamples;
}

//-------------------- SF_VIRTUAL_IO functions that deal with BYTES

//retval is BYTES
static sf_count_t vio_get_filelen(void *userdata)
{
    lazydata *p = static_cast<lazydata*>(userdata);
    return p->dat->size();
}


//count and retval is BYTES
static sf_count_t vio_read(void *ptr, sf_count_t count, void *userdata)
{
    //dbg::qStdOut() << "vio_read! count (bytes)=" << count << "\n";
    lazydata *p = static_cast<lazydata*>(userdata);
    return (sf_count_t) p->dat->read(static_cast<char*>(ptr), count);
}

//count and retval is BYTES
static sf_count_t vio_write(const void *ptr, sf_count_t count, void *userdata)
{
    dbg::qStdOut() << "vio_write() asked to write " << count << " bytes.\n";
    lazydata *p = static_cast<lazydata*>(userdata);
    sf_count_t retval = (sf_count_t) p->dat->write(static_cast<const char*>(ptr), count);
    dbg::qStdOut() << "vio_write wrote " << retval << " bytes.\n";
    return retval;
}

//offset is BYTES, retval is BYTES, and whence is one of SEEK_SET, SEEK_CUR or SEEK_END
static sf_count_t vio_seek(sf_count_t offset, int whence, void *userdata)
{
    dbg::qStdOut() << "vio_seek! offset=" << QString::number(offset) << ", whence=" << QString::number(whence) << "\n";
    lazydata *p = static_cast<lazydata*>(userdata);
    bool seekSucceeded = false;
    switch(whence)
    {
    case SEEK_SET:
        seekSucceeded = p->dat->seek(offset);
        break;
    case SEEK_CUR:
        seekSucceeded = p->dat->seek(vio_tell(userdata) + offset);
        break;
    case SEEK_END:
        seekSucceeded = p->dat->seek(p->dat->size() + offset);
        break;
    }

    sf_count_t retval = vio_tell(userdata);
    dbg::qStdOut() << "vio_seek " << (seekSucceeded ? "SUCCEEDED" : "FAILED") << ", returning " << QString::number(retval) << "\n";
    return retval;
}

//retval is BYTES
static sf_count_t vio_tell(void *userdata)
{
    lazydata *p = static_cast<lazydata*>(userdata);
    return (sf_count_t) p->dat->pos();
}
