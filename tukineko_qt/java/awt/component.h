#ifndef COMPONENT_H
#define COMPONENT_H

//#include <QObject>
//#include <QSize>
//#include "dimension.h"
//#include "image.h"

//class Image_;
class Component //: public QObject
{
//    Q_OBJECT

public:
    Component(/*QObject* parent = nullptr*/);
    virtual ~Component();

//    virtual void setSize(int w, int h);
//    virtual void setPreferredSize(Dimension* d);
//    virtual void setVisible(bool v);
//    virtual void requestFocus();
//    virtual void repaint();

//    /*QImage*/
//    virtual Image_* createImage(int w, int h);

//signals:
//    void repaintSignal();
};

#endif // COMPONENT_H
