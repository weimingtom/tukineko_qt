#ifndef SETCURSORCOMMAND_H
#define SETCURSORCOMMAND_H

#include <QString>
#include "secommand.h"

class SetcursorCommand : public SECommand
{
public:
    SetcursorCommand();
    virtual ~SetcursorCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SETCURSORCOMMAND_H

