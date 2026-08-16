#ifndef JAVA_AWT_MENU_H
#define JAVA_AWT_MENU_H

#include <QString>
#include "event/ActionListener.h"

namespace java {
namespace awt {

class Menu {
public:
    Menu();
    explicit Menu(const QString& str);

    void removeAll();
    void add(const QString& str);
    void addActionListener(event::ActionListener* l);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_MENU_H
