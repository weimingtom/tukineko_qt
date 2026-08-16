#include <QDir>
#include "file_.h"

File_::File_(const QString& path)
    : m_path(path)
    , m_info(path)
{
}

File_::~File_()
{
}

bool File_::exists() const
{
    return m_info.exists();
}

long File_::length() const
{
    return m_info.size();
}

QDateTime File_::lastModified() const
{
    return m_info.lastModified();
}

QString File_::separator()
{
    return QDir::separator();
}
