#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QThread>
#include <QImage>
#include <QBrush>
#include <QColor>
#include <QMenuBar>
#include <QMenu>

class NsWindow;
class MouseListener;
class Graphics_;
class NsData;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow* getInstance();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    MouseListener* currentMouseListener;
    NsWindow* currentNsWindow;
    
    void onStart(const QStringList& argv);
    void refresh();
    void setTitle(const QString& str);
    void addTimer();
    
protected:
    void paintEvent(QPaintEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;
    void closeEvent(QCloseEvent *e) override;

private:
    static MainWindow* instance;
    QTimer* timer;
    QImage* bufferImage;
    QBrush bgBrush;
    
    void DrawGame(QPainter& g);
    
private slots:
    void onTimerTick();

Q_SIGNALS:
    void windowClosed();
};

#endif // MAINWINDOW_H
