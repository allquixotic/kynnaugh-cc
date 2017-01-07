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

#ifndef SPEECHREC_H
#define SPEECHREC_H

#include <google/cloud/speech/v1beta1/cloud_speech.pb.h>
#include <google/cloud/speech/v1beta1/cloud_speech.grpc.pb.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include <grpc++/support/status.h>
#include <grpc/grpc.h>
#include <QtCore>

class speechrec
{
public:
    explicit speechrec();
    QString recognize(char* buf, size_t length);

private:
};

#endif // SPEECHREC_H
