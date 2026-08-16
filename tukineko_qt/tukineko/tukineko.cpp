#include "tukineko.h"
#include "nswindow.h"
#include <QDebug>

void Tukineko::main_(const QStringList& argv)
{
    Q_UNUSED(argv);
    qDebug() << "Tukineko::main";
    // NsWindow is created in MainWindow
}
