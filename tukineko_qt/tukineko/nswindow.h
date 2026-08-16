#ifndef NSWINDOW_H
#define NSWINDOW_H

#include "java/awt/panel.h"
#include "java/awt/frame.h"
#include "java/awt/popupmenu.h"
#include "java/awt/event/mouselistener.h"
#include "java/awt/event/actionlistener.h"
#include "java/awt/event/mouseevent.h"
#include "java/awt/event/actionevent.h"
#include "java/io/inputstream.h"
#include "java/io/outputstream.h"
#include "entry/nsdata.h"
#include "tukineko/nsactionlistener.h"
#include <QPainter>
#include <QMap>
#include <QString>

class NScripter;
class NsTimer;
class NsThread;
class NsImage;
class Image_;
class Graphics_;
class NsText;
class NsColor;

class NsWindow : public Panel_, public MouseListener
{
//    Q_OBJECT

public:
    explicit NsWindow(/*QObject* parent = nullptr*/);
    virtual ~NsWindow();

    // MouseListener interface
    void mouseClicked(MouseEvent* event);// override;
    void mouseEntered(MouseEvent* event);// override;
    void mouseExited(MouseEvent* event);// override;
    void mouseReleased(MouseEvent* event);// override;
    void mousePressed(MouseEvent* event);// override;

    // ActionListener interface
    void actionPerformed(ActionEvent* event);// override;

    // Rendering
    void paint(QPainter* painter);
    void paintB();
    void paintF();
    void repaintWin();
    void blt(int j, int k, int m, int n, int i1, int i2);

    // Text handling
    int putMess(NsText* nt, const QString& mess, NsColor* color, bool attr1, bool attr2);

    // Timer controls
    void timerExit();
    void timerClear();
    int timerRead();

    // Resource management
    void initSar(const QString& filename);
    void initNsa(const QString& filename);
    bool setImageCache(const QString& name);

    // Value storage
    void loadValueStorage(InputStream* is, int* values, QString* strings, int start, int end);
    void saveValueStorage(OutputStream* os, int* values, QString* strings, int start, int end);

    // Image properties
    int getImageWidth(const QString& image);
    int getImageHeight(const QString& image);

    // Menu
    void popupMenuAdd(const QString& str);
    void makemenu(int savenumber, const QString& path, const QString& savenameTitle);
    void createMenuSave(const QString& str);
    void createMenuLoad(const QString& str);

    // Wait/click handling
    void wait(int ms, bool clickable);
    void newpage(bool autoClick);

    // Fade
    void fadeToggle();

    // Window state
    int storageState;
    QString path;
    bool exitFlag;
    NsData* nd;

    // Singleton
    static NsWindow* getInstance() { return s_instance; }

    //FIXME:added
    void close();

private:
    void initGraph();
    void makeFileMenu(Menu* paramMenu, int savenumber, const QString& path, const QString& savenameTitle);
    static Image_* createImage(int w, int h, unsigned int* pix, int off, int scan);
    static void grabPixels(Image_* img, int x, int y, int w, int h, unsigned int* pix, int off, int scansize);
    static void drawString(Graphics_* paramGraphics, const QString& paramString, int x, int y, int charWidth);
    static Color_* getColor(NsColor* color);

private:
    static NsWindow* s_instance;

    NScripter* m_ns;
    PopupMenu* m_menuSys;
    PopupMenu* m_menu;
    Menu* m_menuSave;
    Menu* m_menuLoad;

    Image_* m_frmBuffB;
    Graphics_* m_frmBuffBG;
    Image_* m_frmBuffF;
    Graphics_* m_frmBuffFG;
    Image_* m_frmBuffR;

    NsActionListener* m_al;
    NsTimer* m_timer;

    bool m_isRotate;
};

#endif // NSWINDOW_H
