#include "frame.h"
#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>

Frame::Frame(/*QObject* parent*/)
    : //Component(/*parent*/),
      m_content(nullptr)
    , m_windowAdapter(nullptr)
{
}

Frame::~Frame()
{
}

void Frame::setTitle(const QString& title)
{
    m_title = title;
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->setWindowTitle(title);
    }
}

void Frame::add(Component* comp)
{
    m_content = comp;
}

void Frame::addWindowListener(WindowAdapter* adapter)
{
#if 0
    m_windowAdapter = adapter;
    if (adapter) {
        connect(adapter, &WindowAdapter::windowClosing, [this]() {
            if (m_windowAdapter) {
                WindowEvent* event = new WindowEvent();
                m_windowAdapter->windowClosing(event);
                delete event;
            }
        });
    }
#endif
}

void Frame::pack()
{
    // Pack - resize to minimum size that fits contents
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->adjustSize();
    }
}

void Frame::setResizable(bool resizable)
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->setFixedSize(resizable ? QWIDGETSIZE_MAX : 640, 480);
    }
}

void Frame::setLocationRelativeTo(Component* comp)
{
    Q_UNUSED(comp);
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->move(
            QApplication::desktop()->screen()->rect().center() -
            MainWindow::getInstance()->rect().center()
        );
    }
}

void Frame::setVisible(bool visible)
{
    if (MainWindow::getInstance()) {
        MainWindow::getInstance()->setVisible(visible);
    }
}
