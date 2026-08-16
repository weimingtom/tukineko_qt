#ifndef NSRESOURCE_H
#define NSRESOURCE_H

#include <QString>
#include <QImage>
#include <QMap>

namespace tukineko {

class SarFile;
class NsaFile;

class NsResource {
private:
    static SarFile *sar;
    static NsaFile *nsa;
    static QMap<QString, int> log;

public:
    static void initLog(const QMap<QString, int> &logtable);
    static void initSar(const QString &filename);
    static void initNsa(const QString &filename);

    static QByteArray read(const QString &key);
    static QImage* readImage(const QString &key);
    static QImage* makeAlpha(QImage *image);
};

}

#endif // NSRESOURCE_H
