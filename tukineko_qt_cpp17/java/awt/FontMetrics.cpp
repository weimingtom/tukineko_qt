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
        return fm.horizontalAdvance(str);
    }
    return 0;
}

} // namespace awt
} // namespace java
