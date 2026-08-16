#include "popupmenu.h"
#include <QDebug>

PopupMenu::PopupMenu(const QString& title)
    : Menu(title)
    , m_actionListener(nullptr)
{
}

PopupMenu::~PopupMenu()
{
}

void PopupMenu::show(Component* comp, int x, int y)
{
    Q_UNUSED(comp);
    Q_UNUSED(x);
    Q_UNUSED(y);
    qDebug() << "PopupMenu::show" << getText();
}
