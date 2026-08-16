#ifndef FILE__H
#define FILE__H

#include <QString>
#include <QFileInfo>

class File_
{
public:
    File_(const QString& path);
    File_(const QString& parent, const QString& child);
    
    bool exists() const;
    bool isFile() const;
    bool isDirectory() const;
    QString getName() const;
    QString getParent() const;
    QString getPath() const;
    long length() const;
    bool canRead() const;
    bool canWrite() const;
    bool createNewFile();
    bool mkdir();
    bool mkdirs();
    bool remove();
    bool rename(const QString& dest);
    
    static bool exists(const QString& path);
    static QString separator();

private:
    QString m_path;
    mutable QFileInfo m_info;
    void refresh() const;
};

#endif // FILE__H
