#ifndef MENUSETWINDOWCOMMAND_H
#define MENUSETWINDOWCOMMAND_H

#include <QString>
#include "sfcommand.h"

class MenusetwindowCommand : public SFCommand
{
public:
    MenusetwindowCommand();
    virtual ~MenusetwindowCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MENUSETWINDOWCOMMAND_H
