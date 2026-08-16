#ifndef PANEL__H
#define PANEL__H

#include "component.h"
#include "mouse_listener.h"
#include <QVector>

class Panel_ : public Component
{
public:
    Panel_();
    virtual ~Panel_();
    
    void addMouseListener(MouseListener* listener);
    void removeMouseListener(MouseListener* listener);
    void setCursor(int cursorType);
    void setLayout(void* layout);
    virtual void paint(Graphics_* g) override;
    
protected:
    QVector<MouseListener*> m_mouseListeners;
    int m_cursor;
};

#endif // PANEL__H
