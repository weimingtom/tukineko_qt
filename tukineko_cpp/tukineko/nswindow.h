#ifndef NSWINDOW_H
#define NSWINDOW_H

#include "../java_awt/panel_.h"
#include "../java_awt/mouse_listener.h"
#include <QString>
#include <QStringList>
#include <QMap>
#include <QVector>
#include <QTimer>

class Graphics_;
class Image_;
class Color_;
class NsData;
class NsResource;
class NsText;
class NsButton;
class NsSprite;
class NsEffect;

class MouseEvent;

class NsWindow : public Panel_, public MouseListener
{
public:
    NsWindow();
    virtual ~NsWindow();
    
    void init(const QStringList& argv);
    void run();
    
    // MouseListener interface
    void mousePressed(const MouseEvent& e) override;
    void mouseReleased(const MouseEvent& e) override;
    void mouseClicked(const MouseEvent& e) override;
    
    // Panel_ override
    void paint(Graphics_* g) override;
    
    // Game state methods
    void setBG(Image_* img);
    void setFG(Image_* img);
    void drawText(const QString& text, int x, int y);
    void drawSprite(int num, Image_* img, int x, int y);
    void removeSprite(int num);
    void executeCommand(const QString& cmd);
    
    // Window settings
    int twinLx, twinLy, twinLax, twinLay;  // Text window position
    int twinRx, twinRy, twinRax, twinRay;  // Text window size
    Color_* twinCol;                        // Text window color
    
    // Image caches
    Image_* frmBuffB;  // Background buffer
    Image_* frmBuffBG; // Background image
    Image_* frmBuffF;  // Foreground buffer
    Image_* frmBuffR;  // Role/sprite buffer
    
private:
    NsData* m_data;
    NsResource* m_resource;
    
    QStringList m_argv;
    QString m_currentScript;
    
    // Rendering
    QVector<NsSprite*> m_sprites;
    QVector<NsButton*> m_buttons;
    QVector<NsText*> m_textLines;
    
    // Text rendering state
    int m_curX;
    int m_curY;
    int m_textSpeed;
    QString m_currentText;
    
    // Button tracking
    int m_curBtn;       // Current button index
    bool m_trapFlag;    // Trap flag for button waiting
    int m_trapBtn;      // Trapped button
    
    QTimer* m_timer;
    int m_timerCount;
    
    // Load script files
    void loadScript();
    void processLine(const QString& line);
    void updateDisplay();
};

#endif // NSWINDOW_H
