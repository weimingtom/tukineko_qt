#include "mainwindow.h"
#include "nswindow.h"
#include "java_awt/graphics_.h"
#include "java_awt/image_.h"
#include "tukineko/tukineko.h"

MainWindow* MainWindow::instance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , timer(nullptr)
    , bufferImage(nullptr)
    , bgBrush(Qt::blue)
    , currentMouseListener(nullptr)
    , currentNsWindow(nullptr)
{
    instance = this;
    
    setWindowTitle("tukineko");
    setFixedSize(640, 480);
    setMinimumSize(640, 480);
    setMaximumSize(640, 480);
    
    // Center window on screen
    move(QApplication::primaryScreen()->geometry().center() - rect().center());
    
    // Create buffer image for double buffering
    bufferImage = new QImage(640, 480, QImage::Format_ARGB32);
    
    // Add timer
    addTimer();
    
    // Start game thread
    QThread* t1 = new QThread(this);
    connect(t1, &QThread::started, this, [this]() {
        QStringList args;
        args << "tukineko";
        onStart(args);
    });
    t1->start();
}

MainWindow::~MainWindow()
{
    if (timer) {
        timer->stop();
        delete timer;
    }
    if (bufferImage) {
        delete bufferImage;
    }
}

MainWindow* MainWindow::getInstance()
{
    return instance;
}

void MainWindow::onStart(const QStringList& argv)
{
    qDebug() << "onStart";
    
    // Call Tukineko.main() equivalent
    Tukineko::main(argv);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    
    // Clear buffer
    bufferImage->fill(Qt::blue);
    
    // Draw game content to buffer
    QPainter bufPainter(bufferImage);
    DrawGame(bufPainter);
    bufPainter.end();
    
    // Draw buffer to screen
    painter.drawImage(0, 0, *bufferImage);
}

void MainWindow::DrawGame(QPainter& g)
{
    if (currentNsWindow != nullptr)
    {
        Graphics_* graph = new Graphics_();
        graph->setPainter(&g);
        currentNsWindow->paint(graph);
        delete graph;
    }
}

void MainWindow::refresh()
{
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "MainWindow::mousePressEvent" << e->x() << "," << e->y();
    
    if (currentMouseListener != nullptr)
    {
        MouseEvent ev;
        ev.x = e->x();
        ev.y = e->y();
        currentMouseListener->mousePressed(ev);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug() << "MainWindow::mouseReleaseEvent" << e->x() << "," << e->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    // Optional: implement mouse move tracking
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "MainWindow::keyPressEvent" << e->key();
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    qDebug() << "MainWindow::keyReleaseEvent" << e->key();
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    QApplication::quit();
    e->accept();
}

void MainWindow::addTimer()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTick);
    timer->start(1000); // 1 second interval
}

void MainWindow::onTimerTick()
{
    qDebug() << "timer1_Tick";
}

void MainWindow::setTitle(const QString& str)
{
    setWindowTitle(str);
}
