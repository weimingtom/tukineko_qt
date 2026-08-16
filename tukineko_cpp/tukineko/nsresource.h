#ifndef NSRESOURCE_H
#define NSRESOURCE_H

#include <QString>
#include <QMap>
#include "../java_awt/image_.h"
#include "../java_io/input_stream.h"

class NsImageCache;

class NsResource
{
public:
    NsResource();
    ~NsResource();
    
    void loadArchive(const QString& filename);
    
    Image_* loadImage(const QString& name);
    QByteArray loadData(const QString& name);
    
    bool hasArchive() const { return m_hasArchive; }
    QString archiveName() const { return m_archiveName; }

private:
    bool m_hasArchive;
    QString m_archiveName;
    NsImageCache* m_cache;
    
    // Archive reading
    InputStream* openArchiveEntry(const QString& name);
};

#endif // NSRESOURCE_H
