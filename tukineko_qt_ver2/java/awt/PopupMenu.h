#ifndef JAVA_AWT_POPUPMENU_H
#define JAVA_AWT_POPUPMENU_H

#include <QObject>
#include "Menu.h"
#include "Component.h"

namespace java {
namespace awt {

class PopupMenu : public Menu {
Q_OBJECT
public:
    PopupMenu();
    virtual ~PopupMenu() {}

    void add(const QString& str) { Menu::add(str); }
    void add(const char*str) { Menu::add(str); }
    void add(Menu* menu);
    void addSeparator();
    void show(Component* c, int x, int y);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_POPUPMENU_H
