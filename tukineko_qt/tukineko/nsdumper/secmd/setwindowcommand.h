#ifndef SETWINDOWCOMMAND_H
#define SETWINDOWCOMMAND_H

#include <QString>
#include "secommand.h"

class SetwindowCommand : public SECommand
{
public:
    SetwindowCommand();
    virtual ~SetwindowCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SETWINDOWCOMMAND_H

