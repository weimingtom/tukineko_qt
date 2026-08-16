#include "nsresource.h"
#include "nsimagecache.h"
#include "nsa_file.h"
#include "sar_file.h"
#include "../java_io/file_.h"
#include <QDebug>

NsResource::NsResource()
    : m_hasArchive(false)
    , m_cache(nullptr)
{
    m_cache = new NsImageCache();
}

NsResource::~NsResource()
{
    if (m_cache) delete m_cache;
}

void NsResource::loadArchive(const QString& filename)
{
    if (!File_::exists(filename)) {
        qDebug() << "Archive not found:" << filename;
        return;
    }
    
    m_archiveName = filename;
    m_hasArchive = true;
    qDebug() << "Loaded archive:" << filename;
}

Image_* NsResource::loadImage(const QString& name)
{
    // First check cache
    Image_* cached = m_cache->get(name);
    if (cached) {
        return cached;
    }
    
    // Try to load from archive
    if (m_hasArchive) {
        InputStream* is = openArchiveEntry(name);
        if (is) {
            // Read image data
            QByteArray data;
            int byte;
            while ((byte = is->read()) != -1) {
                data.append(static_cast<char>(byte));
            }
            is->close();
            delete is;
            
            // Create image from data
            Image_* img = new Image_(name);  // This would need actual image loading
            if (!img->isNull()) {
                m_cache->put(name, img);
                return img;
            }
            delete img;
        }
    }
    
    // Try to load from file directly
    if (File_::exists(name)) {
        Image_* img = new Image_(name);
        if (!img->isNull()) {
            m_cache->put(name, img);
            return img;
        }
        delete img;
    }
    
    // Try common image extensions
    QStringList extensions;
    extensions << "" << ".png" << ".jpg" << ".bmp" << ".PNG" << ".PNG" << ".BMP";
    for (const QString& ext : extensions) {
        QString path = name + ext;
        if (File_::exists(path)) {
            Image_* img = new Image_(path);
            if (!img->isNull()) {
                m_cache->put(name, img);
                return img;
            }
            delete img;
        }
    }
    
    qDebug() << "Could not load image:" << name;
    return nullptr;
}

QByteArray NsResource::loadData(const QString& name)
{
    if (m_hasArchive) {
        InputStream* is = openArchiveEntry(name);
        if (is) {
            QByteArray data;
            int byte;
            while ((byte = is->read()) != -1) {
                data.append(static_cast<char>(byte));
            }
            is->close();
            delete is;
            return data;
        }
    }
    
    // Try direct file
    QFile file(name);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();
        return data;
    }
    
    return QByteArray();
}

InputStream* NsResource::openArchiveEntry(const QString& name)
{
    // This would use NsaFile or SarFile to open the entry
    return nullptr;
}
