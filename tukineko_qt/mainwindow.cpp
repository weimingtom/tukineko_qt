#include "mainwindow.h"
#include <QPainter>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>
#include <QCoreApplication>

MainWindow* MainWindow::s_instance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_currentPanel(nullptr)
    , m_nsWindow(nullptr)
    , m_timer(nullptr)
    , m_bufferImage(nullptr)
    , m_gameStarted(false)
{
    s_instance = this;

    // Setup UI
    setupUi();

    // Create NsWindow and start game in a separate thread
    if (1) {
        QTimer::singleShot(100, this, [this]() {
            m_nsWindow = new NsWindow();
            m_gameStarted = true;
            update();
        });
    } else if (0) {
        m_nsWindow = new NsWindow();
        m_gameStarted = true;
        update();
    }
}

void MainWindow::showEvent(QShowEvent* event)
{
    Q_UNUSED(event)
//    m_nsWindow = new NsWindow();
//    m_gameStarted = true;
//    update();

//    QTimer::singleShot(5000, this, [this]() {
//        onshow();
//    });
}

void MainWindow::onshow()
{

}

MainWindow::~MainWindow()
{
    s_instance = nullptr;
    if (m_timer) {
        m_timer->stop();
        delete m_timer;
    }
    if (m_bufferImage) {
        delete m_bufferImage;
    }
}

void MainWindow::setupUi()
{
    setWindowTitle("tukineko");
    setFixedSize(640, 480);
    setMinimumSize(640, 480);
    setMaximumSize(640, 480);

    // Initialize buffer image for double buffering
    m_bufferImage = new QImage(640, 480, QImage::Format_ARGB32);

    // Initialize background brush
    m_bgBrush = QBrush(Qt::blue);

    // Setup timer
    addTimer();

    // Enable mouse tracking
    setMouseTracking(true);
}

void MainWindow::addTimer()
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::onTimerTick);
    m_timer->start(1000); // 1 second interval
}

void MainWindow::onTimerTick()
{
    qDebug() << "timer1_Tick";
}

void MainWindow::refresh()
{
    update();
}

void MainWindow::setTitle(const QString& str)
{
    setWindowTitle(str);
}

MainWindow* MainWindow::getInstance()
{
    return s_instance;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    // Fill background
    painter.fillRect(rect(), m_bgBrush);

    // Draw game content
    drawGame(&painter);
}

void MainWindow::drawGame(QPainter* painter)
{
    if (m_currentPanel != nullptr && m_nsWindow != nullptr) {
        // Draw NsWindow content through its graphics
        m_nsWindow->paint(painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    MouseEvent* me = new MouseEvent();
    me->x = event->x();
    me->y = event->y();

    qDebug() << "MainFormMouseClick" << event->x() << "," << event->y();

    if (m_nsWindow != nullptr) {
        m_nsWindow->mousePressed(me);
    }

    delete me;
    QMainWindow::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    MouseEvent* me = new MouseEvent();
    me->x = event->x();
    me->y = event->y();

    if (m_nsWindow != nullptr) {
        m_nsWindow->mouseReleased(me);
    }

    delete me;
    QMainWindow::mouseReleaseEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    qDebug() << "MainFormKeyDown" << event->key();
    QMainWindow::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    qDebug() << "MainFormKeyUp" << event->key();
    QMainWindow::keyReleaseEvent(event);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (m_nsWindow) {
        m_nsWindow->close();
    }
    event->accept();
    QCoreApplication::quit();
}

// MouseListener implementation
void MainWindow::mouseClicked(MouseEvent* event)
{
    Q_UNUSED(event)
    qDebug() << "mouseClicked";
}

void MainWindow::mouseEntered(MouseEvent* event)
{
    Q_UNUSED(event)
    qDebug() << "mouseEntered";
}

void MainWindow::mouseExited(MouseEvent* event)
{
    Q_UNUSED(event)
    qDebug() << "mouseExited";
}

void MainWindow::mouseReleased(MouseEvent* event)
{
    Q_UNUSED(event)
    qDebug() << "mouseReleased";
}

void MainWindow::mousePressed(MouseEvent* event)
{
    Q_UNUSED(event)
    qDebug() << "mousePressed";
}

// ActionListener implementation
void MainWindow::actionPerformed(ActionEvent* event)
{
    QString cmd = event->getActionCommand();
    qDebug() << "actionPerformed:" << cmd;

    if (cmd == "Exit") {
        close();
    } else if (cmd == "Fade") {
        if (m_nsWindow) {
            m_nsWindow->fadeToggle();
        }
    }
}
