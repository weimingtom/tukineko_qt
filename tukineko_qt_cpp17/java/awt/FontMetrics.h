#ifndef JAVA_AWT_FONTMETRICS_H
#define JAVA_AWT_FONTMETRICS_H

#include <QPainter>
#include <QFont>
#include <QString>

namespace java {
namespace awt {

class FontMetrics {
public:
    QPainter* m_painter;
    QFont m_font;

    FontMetrics();

    int stringWidth(const QString& str);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_FONTMETRICS_H
