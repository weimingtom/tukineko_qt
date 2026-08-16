#include "MainWindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QThread>
#include "java/awt/event/MouseListener.h"
#include "java/awt/event/MouseEvent.h"
#include "java/awt/Panel_.h"
#include "java/awt/Graphics_.h"
#include "tukineko/Tukineko.h"
#include "tukineko/NsWindow.h"

namespace tukineko {

MainWindow* MainWindow::instance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , currentMouseListener(nullptr)
    , currentPanel(nullptr)
    , timer(nullptr)
{
    instance = this;

    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(640, 480);
    setWindowTitle("Tukineko");

    addTimer();

    QThread *t1 = QThread::create([this]() {
        onStart();
    });
    t1->start();
}

MainWindow::~MainWindow()
{
    if (timer) {
        timer->stop();
        delete timer;
    }
    instance = nullptr;
}

MainWindow* MainWindow::getInstance()
{
    return instance;
}

void MainWindow::onStart()
{
    qDebug() << "onStart";
    QStringList args = QCoreApplication::arguments();
    Tukineko::main(args);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    drawGame(painter);
}

void MainWindow::drawGame(QPainter &painter)
{
    painter.fillRect(rect(), Qt::blue);
    if (currentPanel != nullptr) {
        java::awt::Graphics_ graph;
        graph.m_painter = &painter;
        currentPanel->paint(&graph);
    }
}

void MainWindow::refresh()
{
    this->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "MainWindowKeyDown" << event->key();
    QMainWindow::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "MainWindowKeyUp" << event->key();
    QMainWindow::keyReleaseEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "MainWindowMouseClick" << event->x() << "," << event->y();
    if (currentMouseListener != nullptr) {
        java::awt::event::MouseEvent ev;
        ev.x = event->x();
        ev.y = event->y();
        currentMouseListener->mousePressed(&ev);
    }
    QMainWindow::mousePressEvent(event);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    QCoreApplication::exit(0);
}

void MainWindow::addTimer()
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTick);
    timer->start();
}

void MainWindow::onTimerTick()
{
    qDebug() << "timer1_Tick";
}

void MainWindow::setWindowTitle(const QString &str)
{
    QMainWindow::setWindowTitle(str);
}

}
