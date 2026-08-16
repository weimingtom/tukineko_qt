#include "ObjectOutputStream.h"
#include <QJsonDocument>

// Note: NScripter class should be defined elsewhere in the project
// This implementation assumes NScripter has a toJson or similar serialization method

namespace java {
namespace io {

ObjectOutputStream::ObjectOutputStream(ByteArrayOutputStream* o)
    : m_stream(o)
{
}

ObjectOutputStream::~ObjectOutputStream()
{
}

void ObjectOutputStream::writeObject(NScripter* o)
{
    Q_UNUSED(o)
    // JSON serialization - implementation depends on NScripter structure
    // User should implement actual serialization logic here
    QJsonObject jsonObj;
    QJsonDocument doc(jsonObj);
    QByteArray bytes = doc.toJson();
    if (m_stream) {
        m_stream->write(bytes.constData(), 0, bytes.size());
    }
}

void ObjectOutputStream::flush()
{
}

void ObjectOutputStream::close()
{
}

} // namespace io
} // namespace java
