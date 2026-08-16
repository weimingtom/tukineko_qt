#ifndef FRAME_H
#define FRAME_H

//#include "component.h"
#include "panel.h"
#include "event/windowadapter.h"
#include <QString>

class Frame //: public Component
{
//    Q_OBJECT

public:
    Frame(/*QObject* parent = nullptr*/);
    virtual ~Frame();

    void setTitle(const QString& title);
    void add(Component* comp);
    void addWindowListener(WindowAdapter* adapter);
    void pack();
    void setResizable(bool resizable);
    void setLocationRelativeTo(Component* comp);
    void setVisible(bool visible);

private:
    QString m_title;
    Component* m_content;
    WindowAdapter* m_windowAdapter;
};

#endif // FRAME_H
