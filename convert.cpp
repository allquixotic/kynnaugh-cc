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

class lazydata
{
public:
    QBuffer *dat;    //Required to be initialized.
    qint64 samplesize;  //Number of bytes per 1-channel sample.
    qint64 channels; //Must be 1 or 2 (we don't handle multi-channel).
};

//Assume `dat` contains Signed 16-bit LE PCM samples at 48 kHz
//Returns a FLAC file with Signed 16-bit LE samples at 16 kHz.
QByteArray convert::convertRawToFlac(QBuffer *dat, qint32 channes)
{
    if(dat == nullptr || dat->size() == 0)
    {
        QByteArray empty;
        return empty;
    }

    //short to float and (possibly) stereo to mono conversion step
    float *monoSamples;
    int numMonoSamples = toFloatMono(dat, channes, &monoSamples);


    //Resample from 48 kHz to 16 kHz
    int inBufferUsed = 0;
    void *resampler = resample_open(1, 0.01, 8);
    float *outBuffer = new float[numMonoSamples * 4]; //Waste lots of memory for fun and profit; why not?
    int outBufferUsed = resample_process(resampler, 1.0 / 3.0, monoSamples, numMonoSamples, true, &inBufferUsed, outBuffer, numMonoSamples * 4);

    //Encode in FLAC!
    QBuffer outbuf;
    lazydata laz;
    outbuf.open(QIODevice::WriteOnly);
    laz.channels = 1;
    laz.dat = &outbuf;
    laz.samplesize = 2;


    SF_INFO sfi;
    sfi.channels = 1;
    sfi.format = SF_FORMAT_FLAC | SF_FORMAT_PCM_16 | SF_ENDIAN_LITTLE;
    sfi.samplerate = 16000;

    SF_VIRTUAL_IO virt;
    virt.get_filelen = &vio_get_filelen;
    virt.read = &vio_read;
    virt.write = &vio_write;
    virt.seek = &vio_seek;
    virt.tell = &vio_tell;

    SNDFILE *hnd = sf_open_virtual(&virt, SFM_WRITE, &sfi, static_cast<void*>(&laz));
    sf_write_float(hnd, outBuffer, outBufferUsed);
    sf_close(hnd);

    delete[] outBuffer;

    return outbuf.data();
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

    //Create a buffer to store the original data in float format, and read it out from sndfile.
    float *audioIn = new float[origInfo.channels * origInfo.frames];
    sf_read_float(orighandle, audioIn, origInfo.channels * origInfo.frames);

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

    //If the orig was stereo, audioOut is a different buffer, we can discard the original input
    if(channes > 1)
    {
        delete[] audioIn;
    }

    *retval = audioOut;

    return origInfo.frames;
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
    lazydata *p = static_cast<lazydata*>(userdata);
    return (sf_count_t) p->dat->read(static_cast<char*>(ptr), count);
}

//count and retval is BYTES
static sf_count_t vio_write(const void *ptr, sf_count_t count, void *userdata)
{
    lazydata *p = static_cast<lazydata*>(userdata);
    return (sf_count_t) p->dat->write(static_cast<const char*>(ptr), count);
}

//-------------------- SF_VIRTUAL_IO functions that deal with FRAMES

//offset is FRAMES and whence is one of SEEK_SET, SEEK_CUR or SEEK_END
static sf_count_t vio_seek(sf_count_t offset, int whence, void *userdata)
{
    lazydata *p = static_cast<lazydata*>(userdata);
    switch(whence)
    {
    case SEEK_SET:
        p->dat->seek(0);
        break;
    case SEEK_END:
        p->dat->seek(p->dat->size());
        break;
    }

    p->dat->seek(offset * p->samplesize * p->channels);

    return vio_tell(userdata);
}

//retval is FRAMES (1 frame is 1 sample ("item") per channel)
static sf_count_t vio_tell(void *userdata)
{
    lazydata *p = static_cast<lazydata*>(userdata);
    return (sf_count_t) ((p->dat->pos() / p->samplesize) / p->channels);
}
