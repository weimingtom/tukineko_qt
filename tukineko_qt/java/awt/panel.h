#ifndef PANEL_H
#define PANEL_H

#include "component.h"
#include "dimension.h"
#include "image.h"
#include "graphics.h"
#include "popupmenu.h"
#include "event/mouselistener.h"
#include <QPainter>
#include "image.h"

class Panel_ : public Component
{
//    Q_OBJECT

public:
    Panel_(/*QObject* parent = nullptr*/);
    virtual ~Panel_();

    void setSize(int w, int h); //override;
    void addMouseListener(MouseListener* l);
    void add(PopupMenu* menu);
    void setVisible(bool v);// override;
    void setPreferredSize(Dimension* d);// override;
    void requestFocus();// override;
    void repaint();// override;

    /*QImage*/
    Image_* createImage(int w, int h);// override;
    virtual void update(Graphics_* g);
    virtual void paint(Graphics_* g);
    virtual void paint(QPainter* painter);

    MouseListener* getMouseListener() const { return m_mouseListener; }
    //QImage* getBufferImage() const { return m_bufferImage; }

protected:
    MouseListener* m_mouseListener;
    PopupMenu* m_popupMenu;
    //QImage* m_bufferImage;
};

#endif // PANEL_H
