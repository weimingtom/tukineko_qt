#ifndef CLCOMMAND_H
#define CLCOMMAND_H

#include <QString>
#include "vecommand.h"

class ClCommand : public VECommand
{
public:
    ClCommand();
    virtual ~ClCommand();

    bool check(const QString& str);
    void execute();
};

#endif // CLCOMMAND_H

