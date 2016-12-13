# kynnaugh-cc

Kynnaugh-cc ("Kin-aww see-see") is a TeamSpeak 3 plugin for deaf or hearing-impaired users.

## Objectives

 - Provide **Speech-to-text** (also known as speech recognition) capability by recognizing the audio spoken by users in the current channel, and print them to the TS3 chat for the user running the plugin.
 - Provide **Text-to-speech** (also known as digital speech) capability by accepting user input of text and playing the computer-generated audio to the user's current voice channel.
 
## Design

### Where can it run?

 - All platforms and architectures supported by the TeamSpeak 3 client (proprietary) should in theory work.
 - The Windows 7/8.1/10 64-bit platform is the most heavily tested and best-supported platform.
 - Occasionally and lightly tested on macOS Sierra and Ubuntu 16.04 64-bit.

### Dependencies

 - TeamSpeak version 3.1 (currently in public Beta) - proprietary software
 - [Qt](https://www.qt.io) version 5.6.x (any minor version will do) - LGPL 2.1
 - [GStreamer](https://github.com/gstreamer/gstreamer) version 1.x, with the `base` plugins package and the `good` plugins with the FLAC plugin enabled - LGPL 2.1
 - QtGStreamer (tested with [git master](https://github.com/gstreamer/qt-gstreamer)) compiled against the GStreamer 1.x version used above - LGPL 2.1
 - [grpc](https://github.com/grpc/grpc) and grpc++ version 1.x - 3-clause BSD
 - [googleapis](https://github.com/googleapis/googleapis) git master - 3-clause BSD
 - Requires an account and API key with the [Google Cloud Speech API](https://cloud.google.com/speech/) which is not provided in the source distribution.
 - A modern C++11 or later compiler is required. Several dependency libraries use constructs that will not work on old compilers. On Windows, Microsoft Visual Studio 2015 is known to work.
 
### License

The Kynnaugh-cc codebase in this repository is licensed under the [Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0).

