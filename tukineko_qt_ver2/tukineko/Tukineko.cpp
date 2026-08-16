#include <QApplication>
#include <QMainWindow>
#include "Tukineko.h"
#include "NsWindow.h"

namespace tukineko {

void Tukineko::main_(const QStringList &args)
{
    Q_UNUSED(args)
    QMainWindow *win = new QMainWindow;
    win->setWindowTitle("tukineko");
    win->setFixedSize(640, 480);
    win->setMinimumSize(640, 480);
    win->setMaximumSize(640, 480);
    win->setCentralWidget(new NsWindow());
    win->show();
}

}



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringList args;
    tukineko::Tukineko::main_(args);
    return app.exec();
}
