#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace java {
namespace awt {
namespace event {
class MouseListener;
}
class Panel_;
}
}

namespace tukineko {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static MainWindow* getInstance();

    void onStart();
    void refresh();
    void setWindowTitle(const QString &str);

    java::awt::event::MouseListener *currentMouseListener;
    java::awt::Panel_ *currentPanel;

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onTimerTick();

private:
    void addTimer();
    void drawGame(QPainter &painter);

    static MainWindow *instance;
    QTimer *timer;
};

}

#endif // MAINWINDOW_H
