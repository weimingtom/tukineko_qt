#include "font_metrics.h"

FontMetrics::FontMetrics(const QFont& font)
    : m_metrics(font)
{
}

FontMetrics::~FontMetrics()
{
}

int FontMetrics::getAscent() const
{
    return m_metrics.ascent();
}

int FontMetrics::getDescent() const
{
    return m_metrics.descent();
}

int FontMetrics::getHeight() const
{
    return m_metrics.height();
}

int FontMetrics::stringWidth(const QString& str) const
{
    return m_metrics.horizontalAdvance(str);
}

int FontMetrics::charsWidth(const QChar* chars, int off, int len) const
{
    return m_metrics.horizontalAdvance(QString(chars + off, len));
}
