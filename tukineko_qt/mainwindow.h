#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QThread>
#include "java/awt/panel.h"
#include "java/awt/frame.h"
#include "java/awt/event/mouselistener.h"
#include "java/awt/event/actionlistener.h"
#include "tukineko/nswindow.h"
#include "tukineko/tukineko.h"
#include "tukineko/entry/nsdata.h"

class MainWindow : public QMainWindow, public MouseListener, public ActionListener
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

    // MouseListener interface
    void mouseClicked(MouseEvent* event) override;
    void mouseEntered(MouseEvent* event) override;
    void mouseExited(MouseEvent* event) override;
    void mouseReleased(MouseEvent* event) override;
    void mousePressed(MouseEvent* event) override;

    // ActionListener interface
    void actionPerformed(ActionEvent* event) override;

    // Refresh/repaint the window
    void refresh();
    void setTitle(const QString& str);

    // Singleton instance
    static MainWindow* getInstance();

    // NsWindow integration
    NsWindow* getNsWindow() const { return m_nsWindow; }
    Panel_* getCurrentPanel() const { return m_currentPanel; }
    void setCurrentPanel(Panel_* panel) { m_currentPanel = panel; }

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void closeEvent(QCloseEvent* event) override;
    void showEvent(QShowEvent *event) override;

private slots:
    void onTimerTick();
    void onshow();

private:
    void setupUi();
    void drawGame(QPainter* painter);
    void addTimer();

private:
    static MainWindow* s_instance;

    Panel_* m_currentPanel;
    NsWindow* m_nsWindow;
    QTimer* m_timer;
    QImage* m_bufferImage;
    bool m_gameStarted;

    // Colors
    QBrush m_bgBrush;
};

#endif // MAINWINDOW_H
