#ifndef STOPCOMMAND_H
#define STOPCOMMAND_H

#include <QString>
#include "vecommand.h"

class StopCommand : public VECommand
{
public:
    StopCommand();
    virtual ~StopCommand();

    bool check(const QString& str);
    void execute();
};

#endif // STOPCOMMAND_H
