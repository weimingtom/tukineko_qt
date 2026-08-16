#ifndef NSWINDOW_H
#define NSWINDOW_H

#include <QWidget>
#include <QImage>
#include <QMenu>
#include "entry/NsData.h"
#include "global/NsThread.h"
#include "global/NsTimer.h"
#include "java/awt/event/MouseListener.h"
#include "java/awt/event/ActionListener.h"
#include "InputStream.h"
#include "OutputStream.h"
#include "Color_.h"
#include "Graphics_.h"
#include "Image_.h"

namespace java {
namespace awt {
class Menu;
class PopupMenu;
}
}

namespace tukineko {

class NScripter;
class NsActionListener;

class NsWindow : public QWidget, public java::awt::event::MouseListener, public java::awt::event::ActionListener {
    Q_OBJECT

public:
    explicit NsWindow(QWidget *parent = nullptr);
    ~NsWindow();

    // MouseListener interface
    void mouseClicked(java::awt::event::MouseEvent *event_) override;
    void mouseEntered(java::awt::event::MouseEvent *event_) override;
    void mouseExited(java::awt::event::MouseEvent *event_) override;
    void mouseReleased(java::awt::event::MouseEvent *event_) override;
    void mousePressed(java::awt::event::MouseEvent *event_) override;

    // ActionListener interface
    void actionPerformed(java::awt::event::ActionEvent *event_) override;

    void paintB();
    void paintF();
    void blt(int j, int k, int m, int n, int i1, int i2);
    int putMess(NsText *nt, const QString &mess, NsColor *color, bool paramBoolean1, bool paramBoolean2);
    void timerExit();
    void timerClear();
    int timerRead();
    void initSar(const QString &filename);
    void initNsa(const QString &filename);
    bool setImageCache(const QString &name);
    void loadValueStorage(java::io::InputStream *paramInputStream, QVector<int> &paramArrayOfInt, QVector<QString> &paramArrayOfString, int paramInt1, int paramInt2);
    void saveValueStorage(java::io::OutputStream *paramOutputStream, const QVector<int> &paramArrayOfInt, const QVector<QString> &paramArrayOfString, int paramInt1, int paramInt2);
    int getImageWidth(const QString &image);
    int getImageHeight(const QString &image);
    void popupMenuAdd(const QString &str);
    void wait(int paramInt, bool paramBoolean);
    void newpage(bool paramBoolean);
    void makemenu(int savenumber, const QString &path, const QString &savenameTitle);
    void createMenuSave(const QString &str);
    void createMenuLoad(const QString &str);

    NScripter *ns;
    NsThread *thd;
    java::awt::Menu *menuSave;
    java::awt::Menu *menuLoad;
    NsData *ndata;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    void _start();
    void fadeToggle();
    void initGraph();
    void repaintWin();
    void makeFileMenu(java::awt::Menu *paramMenu, int savenumber, const QString &path, const QString &savenameTitle);
    static java::awt::Color_ getColor(NsColor *color);
    static void drawString(java::awt::Graphics_ *paramGraphics, const QString &paramString, int paramInt1, int paramInt2, int paramInt3);

    java::awt::PopupMenu *menuSys;
    java::awt::PopupMenu *menu;
    NsActionListener *al;
    NsTimer *timer;

    java::awt::Image_ *frmBuffB;
    java::awt::Graphics_ *frmBuffBG;
    java::awt::Image_ *frmBuffF;
    java::awt::Graphics_ *frmBuffFG;
    java::awt::Image_ *frmBuffR;
};

}

#endif // NSWINDOW_H
