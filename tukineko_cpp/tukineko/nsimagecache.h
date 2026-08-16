#ifndef NSIMAGECACHE_H
#define NSIMAGECACHE_H

#include <QMap>
#include <QString>
#include "../java_awt/image_.h"

class NsImageCache
{
public:
    NsImageCache(int maxSize = 4);
    ~NsImageCache();
    
    Image_* get(const QString& key);
    void put(const QString& key, Image_* img);
    void clear();
    int size() const;
    void remove(const QString& key);

private:
    QMap<QString, Image_*> m_cache;
    int m_maxSize;
    
    void evictLRU();
    void updateAccess(const QString& key);
};

#endif // NSIMAGECACHE_H
