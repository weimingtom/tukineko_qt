#ifndef NSIMAGECACHE_H
#define NSIMAGECACHE_H

#include <QString>
#include <QVector>
#include "java/awt/component.h"
#include "java/awt/image.h"
#include "nsimage.h"

class NsImageCache
{
public:
    static void init(Component* comp);
    static bool set(const QString& name);
    static Image_* get(const QString& name);

private:
    static QVector<NsImage*>& getCache();

    static QVector<NsImage*> s_cache;
    static Component* s_component;
};

#endif // NSIMAGECACHE_H
