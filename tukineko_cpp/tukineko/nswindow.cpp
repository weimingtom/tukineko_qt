#include "nswindow.h"
#include "nsdata.h"
#include "nsresource.h"
#include "../java_awt/graphics_.h"
#include "../java_awt/image_.h"
#include "../java_awt/color_.h"
#include "../java_awt/mouse_event.h"
#include "../java_io/file_.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

NsWindow::NsWindow()
    : twinLx(0), twinLy(400), twinLax(0), twinLay(400)
    , twinRx(0), twinRy(400), twinRax(640), twinRay(80)
    , twinCol(new Color_(255, 255, 255))
    , frmBuffB(nullptr), frmBuffBG(nullptr)
    , frmBuffF(nullptr), frmBuffR(nullptr)
    , m_data(nullptr), m_resource(nullptr)
    , m_curX(0), m_curY(0), m_textSpeed(20)
    , m_curBtn(-1), m_trapFlag(false), m_trapBtn(-1)
    , m_timer(nullptr), m_timerCount(0)
{
    // Create buffer images (double buffering)
    frmBuffB = Image_::createImage(640, 480);
    frmBuffBG = Image_::createImage(640, 480);
    frmBuffF = Image_::createImage(640, 480);
    frmBuffR = Image_::createImage(640, 480);
    
    // Initialize buffers
    Graphics_* g = frmBuffB->getGraphics();
    if (g) {
        g->setColor(new QColor(0, 0, 0));
        g->fillRect(0, 0, 640, 480);
    }
    
    m_data = new NsData();
    m_resource = new NsResource();
    
    // Add mouse listener
    addMouseListener(this);
}

NsWindow::~NsWindow()
{
    if (m_timer) {
        m_timer->stop();
        delete m_timer;
    }
    if (frmBuffB) delete frmBuffB;
    if (frmBuffBG) delete frmBuffBG;
    if (frmBuffF) delete frmBuffF;
    if (frmBuffR) delete frmBuffR;
    if (m_data) delete m_data;
    if (m_resource) delete m_resource;
}

void NsWindow::init(const QStringList& argv)
{
    m_argv = argv;
    
    // Try to load NSA/SAR archive
    QStringList archives;
    archives << "data.nsa" << "arc.nsa" << "0.nsa";
    for (const QString& arch : archives) {
        if (File_::exists(arch)) {
            m_resource->loadArchive(arch);
            break;
        }
    }
    
    // Load script
    loadScript();
    
    qDebug() << "NsWindow initialized";
}

void NsWindow::run()
{
    // Main game loop - processing is handled by event-driven architecture
    // In Qt, we use signals and slots for asynchronous operations
}

void NsWindow::loadScript()
{
    // Look for NSCRIPT.DAT
    QStringList scriptFiles;
    scriptFiles << "nscript.dat" << "0.txt" << "script.txt";
    
    for (const QString& scriptFile : scriptFiles) {
        if (File_::exists(scriptFile)) {
            QFile file(scriptFile);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                while (!in.atEnd()) {
                    QString line = in.readLine();
                    if (!line.trimmed().isEmpty()) {
                        processLine(line);
                    }
                }
                file.close();
                return;
            }
        }
    }
    
    qDebug() << "No script file found, using default";
}

void NsWindow::processLine(const QString& line)
{
    // Simple command processor
    QString cmd = line.trimmed().toLower();
    
    if (cmd.startsWith("bg ")) {
        // Background command: bg filename
        QString filename = cmd.mid(3).trimmed();
        Image_* img = m_resource->loadImage(filename);
        if (img) {
            setBG(img);
        }
    }
    else if (cmd.startsWith("ld ")) {
        // Load/draw command: ld c filename
        QStringList parts = cmd.mid(3).split(' ', Qt::SkipEmptyParts);
        if (parts.size() >= 2) {
            QString pos = parts[0];
            QString filename = parts[1];
            Image_* img = m_resource->loadImage(filename);
            if (img) {
                setFG(img);
            }
        }
    }
    else if (cmd.startsWith("click")) {
        // Click to continue
        m_trapFlag = true;
    }
    else if (cmd.startsWith("mes ")) {
        // Message: mes text
        QString text = cmd.mid(4).trimmed();
        drawText(text, m_curX, m_curY);
    }
    else if (cmd == "end") {
        // End of game/script
        qDebug() << "End of script";
    }
}

void NsWindow::paint(Graphics_* g)
{
    // Draw background
    if (frmBuffBG && !frmBuffBG->isNull()) {
        g->drawImage(frmBuffBG, 0, 0);
    }
    
    // Draw role/sprites
    if (frmBuffR && !frmBuffR->isNull()) {
        g->drawImage(frmBuffR, 0, 0);
    }
    
    // Draw foreground
    if (frmBuffF && !frmBuffF->isNull()) {
        g->drawImage(frmBuffF, 0, 0);
    }
}

void NsWindow::mousePressed(const MouseEvent& e)
{
    qDebug() << "NsWindow::mousePressed" << e.x << "," << e.y;
    
    // Check button clicks
    for (int i = 0; i < m_buttons.size(); ++i) {
        NsButton* btn = m_buttons[i];
        if (e.x >= btn->x && e.x <= btn->x + btn->width &&
            e.y >= btn->y && e.y <= btn->y + btn->height) {
            m_curBtn = btn->no;
            if (m_trapFlag) {
                m_trapBtn = btn->no;
                m_trapFlag = false;
            }
            break;
        }
    }
}

void NsWindow::mouseReleased(const MouseEvent& e)
{
    // Handle mouse release
}

void NsWindow::mouseClicked(const MouseEvent& e)
{
    if (m_trapFlag) {
        // Continue text or advance
        m_trapFlag = false;
        m_trapBtn = -1;
    }
}

void NsWindow::setBG(Image_* img)
{
    if (img && frmBuffBG) {
        // Copy image to background buffer
        Graphics_* g = frmBuffBG->getGraphics();
        if (g) {
            g->drawImage(img, 0, 0);
        }
    }
}

void NsWindow::setFG(Image_* img)
{
    if (img && frmBuffR) {
        Graphics_* g = frmBuffR->getGraphics();
        if (g) {
            g->drawImage(img, 0, 0);
        }
    }
}

void NsWindow::drawText(const QString& text, int x, int y)
{
    NsText* txt = new NsText();
    txt->text = text;
    txt->x = x;
    txt->y = y;
    txt->color = twinCol;
    m_textLines.append(txt);
    
    // Update cursor position
    m_curX = x;
    m_curY += 24; // Line height
    
    // Draw to foreground buffer
    if (frmBuffF) {
        Graphics_* g = frmBuffF->getGraphics();
        if (g) {
            g->setColor(twinCol->toQColor());
            g->drawString(text, x, y);
        }
    }
    
    // Request redraw
    updateDisplay();
}

void NsWindow::drawSprite(int num, Image_* img, int x, int y)
{
    if (num >= 0 && num < m_sprites.size()) {
        NsSprite* sprite = m_sprites[num];
        sprite->img = img;
        sprite->x = x;
        sprite->y = y;
    }
}

void NsWindow::removeSprite(int num)
{
    if (num >= 0 && num < m_sprites.size()) {
        NsSprite* sprite = m_sprites[num];
        sprite->visible = false;
    }
}

void NsWindow::executeCommand(const QString& cmd)
{
    processLine(cmd);
}

void NsWindow::updateDisplay()
{
    // Trigger window refresh
    // This would typically connect to the main window's refresh
    MainWindow* mainWin = MainWindow::getInstance();
    if (mainWin) {
        mainWin->refresh();
    }
}
