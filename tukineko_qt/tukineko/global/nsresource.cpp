#include "nsresource.h"
#include "sarfile.h"
#include "nsafile.h"
#include "java/io/fileinputstream.h"
#include "java/awt/toolkit.h"
#include "java/awt/mediatracker.h"
#include <QDebug>
#include "runtime.h"

QMap<QString, int>* NsResource::s_log = nullptr;
SarFile* NsResource::s_sar = nullptr;
NsaFile* NsResource::s_nsa = nullptr;

void NsResource::initLog(QMap<QString, int>& logtable)
{
    s_log = &logtable;
}

void NsResource::initSar(const QString& filename, Component* comp)
{
    Q_UNUSED(comp);
    try {
        s_sar = new SarFile(filename);
        s_nsa = nullptr;
    } catch (...) {
        qDebug() << "resource:" << filename;
    }
}

void NsResource::initNsa(const QString& filename, Component* comp)
{
    Q_UNUSED(comp);
    try {
        s_sar = nullptr;
        s_nsa = new NsaFile(filename);
    } catch (...) {
        qDebug() << "resource:" << filename;
    }
}

QByteArray NsResource::read(const QString& key)
{
    QByteArray bytes;
    try {
        int len = 0;
        InputStream* istream = nullptr;

        if (s_sar) {
            // Handle SAR file
            qDebug() << "Reading from SAR:" << key;
        } else if (s_nsa) {
            // Handle NSA file
            qDebug() << "Reading from NSA:" << key;
        }

        if (istream) {
            //FIXME:???
            //bytes = istream->readAll();
            istream->close();
            delete istream;
        }
    } catch (...) {
        qDebug() << "read resource";
    }

    QString upperKey = key.toUpper();
    if (s_log && !s_log->contains(upperKey)) {
        s_log->insert(upperKey, 1);
    }

    return bytes;
}

Image_* NsResource::readImage(const QString& key)
{
    Runtime::getRuntime()->runFinalization();
    Runtime::getRuntime()->gc();

    int offsetFlag = 0;
    int offset = 0;

    if (key.startsWith(":")) {
        if (key.startsWith(":a;")) {
            offsetFlag = 1;
            offset = 3;
        } else if (key.startsWith(":c;")) {
            offset = 3;
        } else {
            qDebug() << "image:" << key;
            return nullptr;
        }
    }

    QByteArray bytes = read(key.mid(offset));
    if (bytes.isEmpty()) {
        return nullptr;
    }

    Image_* image = Toolkit::getDefaultToolkit()->createImage(bytes);
    // Note: MediaTracker handling would go here

    if (offsetFlag == 1) {
        return makeAlpha(image);
    }
    return image;
}

Image_* NsResource::makeAlpha(Image_* image)
{
    int w = image->getWidth();
    int h = image->getHeight();
    unsigned int* pix = new unsigned int[w * h];

    // PixelGrabber would extract pixels here

    for (int m = 0; m < h; ++m) {
        for (int k = 0; k < w >> 1; ++k) {
            unsigned int n1 = pix[k + (w >> 1) + m * w] & 0xFF;
            unsigned int n2 = (n1 < 64) ? 255 : 0;
            unsigned int n = n2 << 24;
            pix[k + m * w] = (pix[k + m * w] & 0xFFFFFF) | n;
        }
    }

    Image_* result = Toolkit::getDefaultToolkit()->createImage(w >> 1, h, pix, 0, w);
    delete[] pix;
    return result;
}
