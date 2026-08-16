#include <QtGlobal>
#include "FontMetrics.h"

namespace java {
namespace awt {

FontMetrics::FontMetrics()
    : m_painter(nullptr)
{
}

int FontMetrics::stringWidth(const QString& str)
{
    if (m_painter) {
        QFontMetrics fm(m_font);
#if QT_VERSION < QT_VERSION_CHECK(5, 11, 0)
        return fm.width(str);
#else
        return fm.horizontalAdvance(str);
#endif
    }
    return 0;
}

} // namespace awt
} // namespace java
