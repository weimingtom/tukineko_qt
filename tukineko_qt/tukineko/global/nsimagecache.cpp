#include "nsimagecache.h"
#include "nsresource.h"
#include "java/awt/toolkit.h"
#include "java/io/file_.h"
#include <QDebug>

QVector<NsImage*> NsImageCache::s_cache;
Component* NsImageCache::s_component = nullptr;

void NsImageCache::init(Component* comp)
{
    s_cache.clear();
    s_component = comp;
}

bool NsImageCache::set(const QString& name)
{
    NsImage* img = new NsImage(name);
    File_ file(name);
    if (file.exists()) {
        img->image = Toolkit::getDefaultToolkit()->createImage(name);
    } else {
        img->image = nullptr;
    }
    s_cache.append(img);
    return img->image != nullptr;
}

Image_* NsImageCache::get(const QString& name)
{
    NsImage target(name);
    for (int i = 0; i < s_cache.size(); ++i) {
        if (s_cache[i]->name == name) {
            NsImage* img = s_cache[i];
            s_cache.removeAt(i);
            if (s_cache.size() >= 4) {
                delete s_cache[0];
                s_cache.removeAt(0);
            }
            s_cache.append(img);
            return img->getImage();
        }
    }

    if (s_cache.size() >= 4) {
        delete s_cache[0];
        s_cache.removeAt(0);
    }

    NsImage* newImg = new NsImage(name);
    newImg->setImage(NsResource::readImage(name));
    s_cache.append(newImg);
    return newImg->getImage();
}
