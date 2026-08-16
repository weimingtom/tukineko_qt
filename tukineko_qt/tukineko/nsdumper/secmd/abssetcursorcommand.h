#ifndef ABSSETCURSORCOMMAND_H
#define ABSSETCURSORCOMMAND_H

#include <QString>
#include "secommand.h"

class AbssetcursorCommand : public SECommand
{
public:
    AbssetcursorCommand();
    virtual ~AbssetcursorCommand();

    bool check(const QString& str);
    void execute();
};

#endif // ABSSETCURSORCOMMAND_H

