#include "tukineko.h"
#include "nswindow.h"
#include "../mainwindow.h"
#include <QDebug>

NsWindow* Tukineko::s_mainWindow = nullptr;

void Tukineko::main(const QStringList& argv)
{
    qDebug() << "Tukineko::main starting...";
    
    // Create and initialize the main game window
    s_mainWindow = new NsWindow();
    
    // Set it as the current window in MainWindow
    MainWindow* mainWin = MainWindow::getInstance();
    if (mainWin) {
        mainWin->currentNsWindow = s_mainWindow;
        mainWin->currentMouseListener = s_mainWindow;
    }
    
    // Initialize the NScripter engine
    s_mainWindow->init(argv);
    
    // Start the game loop
    s_mainWindow->run();
    
    qDebug() << "Tukineko::main finished";
}
