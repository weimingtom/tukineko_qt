#ifndef JAVA_AWT_FRAME_H
#define JAVA_AWT_FRAME_H

#include "Panel_.h"
#include "event/WindowAdapter.h"

namespace java {
namespace awt {

class Frame {
public:
    Frame();

    void add(Panel_* p);
    void addWindowListener(event::WindowAdapter* wa);
    void pack();
    void setResizable(bool r);
    void setLocationRelativeTo(QObject* o);
    void setVisible(bool v);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_FRAME_H
