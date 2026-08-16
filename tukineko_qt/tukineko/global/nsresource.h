#ifndef NSRESOURCE_H
#define NSRESOURCE_H

#include <QString>
#include <QMap>
#include "java/awt/component.h"
#include "java/awt/image.h"

class SarFile;
class NsaFile;

class NsResource
{
public:
    static void initLog(QMap<QString, int>& logtable);
    static void initSar(const QString& filename, Component* comp);
    static void initNsa(const QString& filename, Component* comp);

    static QByteArray read(const QString& key);
    static Image_* readImage(const QString& key);
    static Image_* makeAlpha(Image_* image);

private:
    static QMap<QString, int>* s_log;
    static SarFile* s_sar;
    static NsaFile* s_nsa;
};

#endif // NSRESOURCE_H
