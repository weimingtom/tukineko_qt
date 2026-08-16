#ifndef TUKINEKO_MAIN_H
#define TUKINEKO_MAIN_H

#include <QString>
#include <QStringList>

class NsWindow;

class Tukineko
{
public:
    static void main(const QStringList& argv);
    
private:
    static NsWindow* s_mainWindow;
};

#endif // TUKINEKO_MAIN_H
