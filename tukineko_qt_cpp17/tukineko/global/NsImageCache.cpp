#include "NsImageCache.h"
#include "NsResource.h"
#include <QFile>
#include <QImageReader>

namespace tukineko {

QList<NsImage> NsImageCache::cache;

void NsImageCache::init() {
    cache.clear();
}

bool NsImageCache::set(const QString &name) {
    NsImage img(name);
    QFile file(name);
    if (file.exists()) {
        img.image = new QImage();
        if (!img.image->load(name)) {
            delete img.image;
            img.image = nullptr;
        }
    } else {
        img.image = nullptr;
    }
    cache.append(img);
    return img.image != nullptr;
}

QImage* NsImageCache::get(const QString &name) {
    NsImage img(name);
    int i = -1;
    for (int j = 0; j < cache.size(); ++j) {
        if (cache[j] == img) {
            i = j;
            break;
        }
    }
    if (i >= 0) {
        img = cache[i];
        cache.removeAt(i);
    } else {
        if (cache.size() >= 4) {
            cache.removeFirst();
        }
        img.setImage(NsResource::readImage(name));
    }
    cache.append(img);
    return img.getImage();
}

}
