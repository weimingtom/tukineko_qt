#ifndef MENUWINDOWCOMMAND_H
#define MENUWINDOWCOMMAND_H

#include <QString>
#include "vecommand.h"

class MenuwindowCommand : public VECommand
{
public:
    MenuwindowCommand();
    virtual ~MenuwindowCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MENUWINDOWCOMMAND_H
