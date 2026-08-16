#ifndef NSIMAGECACHE_H
#define NSIMAGECACHE_H

#include <QList>
#include <QString>
#include <QImage>
#include "NsImage.h"

namespace tukineko {

class NsImageCache {
private:
    static QList<NsImage> cache;

public:
    static void init();
    static bool set(const QString &name);
    static QImage* get(const QString &name);
};

}

#endif // NSIMAGECACHE_H
