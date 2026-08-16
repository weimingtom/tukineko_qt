#ifndef JAVA_AWT_COLOR_H
#define JAVA_AWT_COLOR_H

#include <QColor>

namespace java {
namespace awt {

class Color_ {
public:
    QColor color_;

    Color_();
    Color_(int r, int g, int b);
    Color_(quint32 rgba, bool hasalpha);

    static Color_ black;
    static Color_ white;
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_COLOR_H
