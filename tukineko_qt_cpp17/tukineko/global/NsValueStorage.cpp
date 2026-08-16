#include "NsValueStorage.h"
#include <QTextCodec>
#include <QDebug>

namespace tukineko {

void NsValueStorage::save(QDataStream &out, const QVector<int> &paramArrayOfInt,
                          const QVector<QString> &paramArrayOfString, int paramInt1, int paramInt2) {
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    if (!codec) {
        codec = QTextCodec::codecForName("SJIS");
    }

    for (int i = paramInt1; i <= paramInt2; i++) {
        out << static_cast<qint8>(paramArrayOfInt[i] & 0xFF);
        out << static_cast<qint8>((paramArrayOfInt[i] >> 8) & 0xFF);
        out << static_cast<qint8>((paramArrayOfInt[i] >> 16) & 0xFF);
        out << static_cast<qint8>((paramArrayOfInt[i] >> 24) & 0xFF);

        QByteArray arrayOfByte;
        if (codec) {
            arrayOfByte = codec->fromUnicode(paramArrayOfString[i]);
        } else {
            arrayOfByte = paramArrayOfString[i].toLocal8Bit();
        }
        if (arrayOfByte.size() > 0) {
            out.writeRawData(arrayOfByte.constData(), arrayOfByte.size());
        }
        out << static_cast<qint8>(0);
    }
}

void NsValueStorage::load(QDataStream &in, QVector<int> &paramArrayOfInt,
                          QVector<QString> &paramArrayOfString, int paramInt1, int paramInt2) {
    QByteArray arrayOfByte(1024, 0);
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    if (!codec) {
        codec = QTextCodec::codecForName("SJIS");
    }

    try {
        for (int i = paramInt1; i <= paramInt2; i++) {
            qint8 b0, b1, b2, b3;
            in >> b0 >> b1 >> b2 >> b3;
            paramArrayOfInt[i] = (static_cast<quint8>(b0)) |
                                 (static_cast<quint8>(b1) << 8) |
                                 (static_cast<quint8>(b2) << 16) |
                                 (static_cast<quint8>(b3) << 24);

            int j = 0;
            for (; j < 1024; j++) {
                qint8 bb0;
                in >> bb0;
                arrayOfByte[j] = bb0;
                if (arrayOfByte[j] == 0)
                    break;
            }
            if (j == 0) {
                paramArrayOfString[i] = "";
            } else {
                if (codec) {
                    paramArrayOfString[i] = codec->toUnicode(arrayOfByte.constData(), j);
                } else {
                    paramArrayOfString[i] = QString::fromLocal8Bit(arrayOfByte.constData(), j);
                }
            }
        }
    } catch (...) {
        qDebug() << "IOException: load";
    }
}

}
