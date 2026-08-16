#include "fontmetrics.h"

FontMetrics::FontMetrics()
    : m_metrics(nullptr)
{
    m_metrics = new QFontMetrics(m_font);
}

FontMetrics::FontMetrics(const QFont& font)
    : m_font(font)
    , m_metrics(nullptr)
{
    m_metrics = new QFontMetrics(m_font);
}

FontMetrics::~FontMetrics()
{
    if (m_metrics) {
        delete m_metrics;
        m_metrics = nullptr;
    }
}

void FontMetrics::setFont(const QFont& font)
{
    m_font = font;
    if (m_metrics) {
        delete m_metrics;
    }
    m_metrics = new QFontMetrics(m_font);
}

int FontMetrics::stringWidth(const QString& str)
{
    if (m_metrics) {
//        return m_metrics->horizontalAdvance(str);
        return m_metrics->width(str);
    }
    return 0;
}

int FontMetrics::height() const
{
    if (m_metrics) {
        return m_metrics->height();
    }
    return 0;
}

int FontMetrics::ascent() const
{
    if (m_metrics) {
        return m_metrics->ascent();
    }
    return 0;
}

int FontMetrics::descent() const
{
    if (m_metrics) {
        return m_metrics->descent();
    }
    return 0;
}

void FontMetrics::setPainter(QPainter* painter)
{
    m_painter = painter;
}


