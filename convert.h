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

#ifndef CONVERT_H
#define CONVERT_H

#include <QtCore>

class convert : public QObject
{
    Q_OBJECT
public:
    explicit convert();
    QBuffer *convertRawToFlac(QBuffer *dat, qint32 channes);
private:
    void *resampler;
};

#endif // CONVERT_H
