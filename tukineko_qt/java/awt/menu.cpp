#include "menu.h"

Menu::Menu(const QString& title)
    : m_title(title)
    , m_actionListener(nullptr)
{
}

Menu::~Menu()
{
}

void Menu::add(const QString& label)
{
    m_items.append(label);
}

void Menu::addSeparator()
{
    m_items.append("---");
}

void Menu::removeAll()
{
    m_items.clear();
}

void Menu::addActionListener(ActionListener* listener)
{
    m_actionListener = listener;
}

QString Menu::getLabel(int index) const
{
    if (index >= 0 && index < m_items.size()) {
        return m_items[index];
    }
    return QString();
}

int Menu::getItemCount() const
{
    return m_items.size();
}
