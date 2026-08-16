#ifndef FONT_METRICS_H
#define FONT_METRICS_H

#include <QFontMetrics>

class FontMetrics
{
public:
    FontMetrics(const QFont& font);
    ~FontMetrics();
    
    int getAscent() const;
    int getDescent() const;
    int getHeight() const;
    int stringWidth(const QString& str) const;
    int charsWidth(const QChar* chars, int off, int len) const;

private:
    QFontMetrics m_metrics;
};

#endif // FONT_METRICS_H
