#ifndef GOTOCOMMAND_H
#define GOTOCOMMAND_H

#include <QString>
#include "fecommand.h"

class GotoCommand : public FECommand
{
public:
    GotoCommand();
    virtual ~GotoCommand();

    bool check(const QString& str);
    void execute();
};

#endif // GOTOCOMMAND_H
