#include "NsResource.h"
#include "../file/SarFile.h"
#include "../file/SarEntry.h"
#include "../file/NsaFile.h"
#include "../file/NsaEntry.h"
#include <QDebug>
#include <QBuffer>

namespace tukineko {

SarFile *NsResource::sar = nullptr;
NsaFile *NsResource::nsa = nullptr;
QMap<QString, int> NsResource::log;

void NsResource::initLog(const QMap<QString, int> &logtable) {
    log = logtable;
}

void NsResource::initSar(const QString &filename) {
    if (sar) {
        delete sar;
        sar = nullptr;
    }
    if (nsa) {
        delete nsa;
        nsa = nullptr;
    }
    sar = new SarFile(filename);
}

void NsResource::initNsa(const QString &filename) {
    if (sar) {
        delete sar;
        sar = nullptr;
    }
    if (nsa) {
        delete nsa;
        nsa = nullptr;
    }
    nsa = new NsaFile(filename);
}

QByteArray NsResource::read(const QString &key) {
    QByteArray bytes;
    try {
        int i = 0;
        QIODevice *istream = nullptr;
        if (sar != nullptr) {
            SarEntry localSarEntry_ = sar->getSarEntry(key);
            SarEntry *localSarEntry = &localSarEntry_;
            if (localSarEntry == nullptr) {
                qDebug() << "no resource:" << key;
                return QByteArray();
            }
            i = localSarEntry->length_();
            bytes.resize(i);
            istream = sar->getInputStream(localSarEntry_);
        } else if (nsa != nullptr) {
            NsaEntry ne_ = nsa->getNsaEntry(key);
            NsaEntry *ne = &ne_;
            if (ne == nullptr) {
                qDebug() << "no resource:" << key;
                return QByteArray();
            }
            i = ne->length_();
            bytes.resize(i);
            istream = nsa->getInputStream(ne_);
        } else {
            return QByteArray();
        }
        if (istream) {
            istream->read(bytes.data(), i);
            istream->close();
            delete istream;
        }
    } catch (...) {
        qDebug() << "read resource";
    }
    QString str = key.toUpper();
    if (!log.contains(str)) {
        log.insert(str, 1);
    }
    return bytes;
}

QImage* NsResource::readImage(const QString &key) {
    int j = 0;
    int i = 0;
    QString actualKey = key;
    if (key.startsWith(":")) {
        if (key.startsWith(":a;")) {
            i = 1;
            j = 3;
        } else if (key.startsWith(":c;")) {
            j = 3;
        } else {
            qDebug() << "image:" << key;
            return nullptr;
        }
        actualKey = key.mid(j);
    }
    QByteArray bytes = read(actualKey);
    if (bytes.isEmpty()) {
        return nullptr;
    }
    QImage *image = new QImage();
    if (!image->loadFromData(bytes)) {
        delete image;
        return nullptr;
    }
    if (i == 1) {
        QImage *alphaImage = makeAlpha(image);
        delete image;
        return alphaImage;
    }
    return image;
}

QImage* NsResource::makeAlpha(QImage *image) {
    int w = image->width();
    int h = image->height();
    QImage sourceImage = image->convertToFormat(QImage::Format_ARGB32);
    QVector<uint> pix(w * h);
    for (int y = 0; y < h; ++y) {
        const QRgb *scanline = reinterpret_cast<const QRgb*>(sourceImage.scanLine(y));
        for (int x = 0; x < w; ++x) {
            pix[y * w + x] = scanline[x];
        }
    }
    for (int m = 0; m < h; ++m) {
        for (int k = 0; k < w >> 1; ++k) {
            uint n1 = pix[(k + (w >> 1) + m * w)] & 0xFF;
            uint n2 = 0;
            if (n1 < 64) {
                n2 = 255;
            } else {
                n2 = 0;
            }
            uint n = n2 << 24;
            pix[(k + m * w)] = (pix[(k + m * w)] & 0xFFFFFF) | n;
        }
    }
    QImage *result = new QImage(w >> 1, h, QImage::Format_ARGB32);
    for (int y = 0; y < h; ++y) {
        QRgb *scanline = reinterpret_cast<QRgb*>(result->scanLine(y));
        for (int x = 0; x < (w >> 1); ++x) {
            scanline[x] = pix[y * w + x];
        }
    }
    return result;
}

}
