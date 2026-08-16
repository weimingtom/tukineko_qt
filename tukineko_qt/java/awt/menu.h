#ifndef MENU_H
#define MENU_H

#include <QString>
#include <QVector>
#include "event/actionlistener.h"

class Menu
{
public:
    Menu(const QString& title = "");
    virtual ~Menu();

    void add(const QString& label);
    void addSeparator();
    void removeAll();
    void addActionListener(ActionListener* listener);

    QString getLabel(int index) const;
    int getItemCount() const;
    QString getText() const { return m_title; }

private:
    QString m_title;
    QVector<QString> m_items;
    ActionListener* m_actionListener;
};

#endif // MENU_H
