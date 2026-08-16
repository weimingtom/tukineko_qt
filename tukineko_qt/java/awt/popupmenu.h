#ifndef POPUPMENU_H
#define POPUPMENU_H

#include "menu.h"
#include "event/actionlistener.h"
#include "component.h"

class PopupMenu : public Menu
{
public:
    explicit PopupMenu(const QString& title = "");
    virtual ~PopupMenu();

    void show(Component* comp, int x, int y);

    //FIXME:added
    void add(Menu *menu) {Q_UNUSED(menu)}
//signals:
//    void actionPerformed(const QString& command);

private:
    ActionListener* m_actionListener;
};

#endif // POPUPMENU_H
