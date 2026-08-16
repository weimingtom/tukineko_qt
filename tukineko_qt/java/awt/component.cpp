#include "component.h"
#include <QImage>
#include <QDebug>
#include "mainwindow.h"

Component::Component(/*QObject* parent*/)
    //: QObject(parent)
{
}

Component::~Component()
{
}

#if 0
void Component::setSize(int w, int h)
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->resize(w, h);
    }
}

void Component::setPreferredSize(Dimension* d)
{
    if (d) {
        setSize(d->w, d->h);
    }
}

void Component::setVisible(bool v)
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->setVisible(v);
    }
}

void Component::requestFocus()
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->setFocus();
    }
}

void Component::repaint()
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->refresh();
    }
}

//QImage*
Image_* Component::createImage(int w, int h)
{
    Image_* result = new Image_();
    result->m_bufferImage = new QImage(w, h, QImage::Format_ARGB32);
    return result;
}
#endif
