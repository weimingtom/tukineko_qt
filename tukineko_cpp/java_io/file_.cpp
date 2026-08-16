#include "file_.h"
#include <QDir>

File_::File_(const QString& path)
    : m_path(path)
{
    refresh();
}

File_::File_(const QString& parent, const QString& child)
    : m_path(parent + "/" + child)
{
    refresh();
}

void File_::refresh() const
{
    m_info.setFile(m_path);
}

bool File_::exists() const
{
    refresh();
    return m_info.exists();
}

bool File_::isFile() const
{
    refresh();
    return m_info.isFile();
}

bool File_::isDirectory() const
{
    refresh();
    return m_info.isDir();
}

QString File_::getName() const
{
    refresh();
    return m_info.fileName();
}

QString File_::getParent() const
{
    refresh();
    return m_info.path();
}

QString File_::getPath() const
{
    return m_path;
}

long File_::length() const
{
    refresh();
    return m_info.size();
}

bool File_::canRead() const
{
    refresh();
    return m_info.isReadable();
}

bool File_::canWrite() const
{
    refresh();
    return m_info.isWritable();
}

bool File_::createNewFile()
{
    QFile file(m_path);
    return file.open(QIODevice::WriteOnly);
}

bool File_::mkdir()
{
    return QDir().mkdir(m_path);
}

bool File_::mkdirs()
{
    return QDir().mkpath(m_path);
}

bool File_::remove()
{
    refresh();
    if (m_info.isFile()) {
        return QFile::remove(m_path);
    } else if (m_info.isDir()) {
        return QDir().rmdir(m_path);
    }
    return false;
}

bool File_::rename(const QString& dest)
{
    return QFile::rename(m_path, dest);
}

bool File_::exists(const QString& path)
{
    return QFileInfo(path).exists();
}

QString File_::separator()
{
    return QDir::separator() == '/' ? "/" : "\\";
}
