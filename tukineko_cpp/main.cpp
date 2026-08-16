#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Convert argv to vector of strings (like C# Environment.GetCommandLineArgs)
    QStringList args = QCoreApplication::arguments();
    QStringList argvQt;
    argvQt << args[0]; // program name
    for (int i = 1; i < args.size(); ++i) {
        argvQt << args[i];
    }
    
    MainWindow w;
    w.show();
    
    return a.exec();
}
