#include "nsimagecache.h"

NsImageCache::NsImageCache(int maxSize)
    : m_maxSize(maxSize)
{
}

NsImageCache::~NsImageCache()
{
    clear();
}

Image_* NsImageCache::get(const QString& key)
{
    auto it = m_cache.find(key);
    if (it != m_cache.end()) {
        updateAccess(key);
        return it.value();
    }
    return nullptr;
}

void NsImageCache::put(const QString& key, Image_* img)
{
    if (m_cache.contains(key)) {
        delete m_cache[key];
    }
    
    while (m_cache.size() >= m_maxSize) {
        evictLRU();
    }
    
    m_cache[key] = img;
    updateAccess(key);
}

void NsImageCache::clear()
{
    for (auto it = m_cache.begin(); it != m_cache.end(); ++it) {
        if (it.value()) delete it.value();
    }
    m_cache.clear();
}

int NsImageCache::size() const
{
    return m_cache.size();
}

void NsImageCache::remove(const QString& key)
{
    auto it = m_cache.find(key);
    if (it != m_cache.end()) {
        if (it.value()) delete it.value();
        m_cache.erase(it);
    }
}

void NsImageCache::evictLRU()
{
    // Simple LRU eviction - remove first item
    if (!m_cache.isEmpty()) {
        auto it = m_cache.begin();
        if (it.value()) delete it.value();
        m_cache.erase(it);
    }
}

void NsImageCache::updateAccess(const QString& key)
{
    // In a full implementation, this would update LRU order
    Q_UNUSED(key);
}
