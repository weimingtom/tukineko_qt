#ifndef MENUFULLCOMMAND_H
#define MENUFULLCOMMAND_H

#include <QString>
#include "vecommand.h"

class MenufullCommand : public VECommand
{
public:
    MenufullCommand();
    virtual ~MenufullCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MENUFULLCOMMAND_H
