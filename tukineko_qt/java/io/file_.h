#ifndef FILE__H
#define FILE__H

#include <QString>
#include <QFileInfo>
#include <QDateTime>

class File_
{
public:
    File_(const QString& path);
    virtual ~File_();

    bool exists() const;
    long length() const;
    QDateTime lastModified() const;

    static QString separator();

private:
    QString m_path;
    QFileInfo m_info;
};

#endif // FILE__H
