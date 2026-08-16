#ifndef JAVA_AWT_PANEL_H
#define JAVA_AWT_PANEL_H

#include "Component.h"
#include "Image_.h"
#include "Graphics_.h"
#include "Dimension.h"

namespace java {
namespace awt {
namespace event {
    class MouseListener;
}
class PopupMenu;

class Panel_ : public Component {
    Q_OBJECT
public:
    Panel_();

    void setSize(int w, int h);
    void addMouseListener(event::MouseListener* l);
    void add(PopupMenu* menu);
    void setVisible(bool v);
    void setPreferredSize(Dimension* d);
    void requestFocus();
    void repaint();

    Image_* createImage(int w, int h);
    virtual void update(Graphics_* g);
    virtual void paint(Graphics_* g);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_PANEL_H
