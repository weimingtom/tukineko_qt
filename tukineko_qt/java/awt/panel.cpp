#include "panel.h"
#include "mainwindow.h"
#include <QDebug>

Panel_::Panel_(/*QObject* parent*/)
    : Component(/*parent*/)
    , m_mouseListener(nullptr)
    , m_popupMenu(nullptr)
    //, m_bufferImage(nullptr)
{
    // Set as current panel in MainWindow
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->setCurrentPanel(this);
    }
}

Panel_::~Panel_()
{
    //if (m_bufferImage) {
    //    delete m_bufferImage;
    //    m_bufferImage = nullptr;
    //}
}

void Panel_::setSize(int w, int h)
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->resize(w, h + (h - MainWindow::getInstance()->height()));
    }
}

void Panel_::addMouseListener(MouseListener* l)
{
    m_mouseListener = l;
}

void Panel_::add(PopupMenu* menu)
{
    m_popupMenu = menu;
}

void Panel_::setVisible(bool v)
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->setVisible(v);
    }
}

void Panel_::setPreferredSize(Dimension* d)
{
    if (d) {
        setSize(d->w, d->h);
    }
}

void Panel_::requestFocus()
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->setFocus();
    }
}

void Panel_::repaint()
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->update();
    }
}

Image_* Panel_::createImage(int w, int h)
{
    //if (m_bufferImage) {
    //    delete m_bufferImage;
    //}
    QImage* m_bufferImage = new QImage(w, h, QImage::Format_ARGB32);
    m_bufferImage->fill(Qt::black);
//    return m_bufferImage;
    Image_* result = new Image_();
    result->m_bufferImage = m_bufferImage;
    return result;
}

void Panel_::update(Graphics_* g)
{
    Q_UNUSED(g);
}

void Panel_::paint(Graphics_* g)
{
    Q_UNUSED(g);
}

void Panel_::paint(QPainter* painter)
{
    Q_UNUSED(painter);
}
