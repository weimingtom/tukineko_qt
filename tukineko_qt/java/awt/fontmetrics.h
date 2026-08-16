#ifndef FONTMETRICS_H
#define FONTMETRICS_H

#include <QFontMetrics>
#include <QString>

class FontMetrics
{
public:
    FontMetrics();
    FontMetrics(const QFont& font);
    virtual ~FontMetrics();

    void setFont(const QFont& font);
    int stringWidth(const QString& str);
    int height() const;
    int ascent() const;
    int descent() const;

    void setPainter(QPainter* painter);

private:
    QFont m_font;
    QFontMetrics* m_metrics;
    QPainter* m_painter;
};

#endif // FONTMETRICS_H
