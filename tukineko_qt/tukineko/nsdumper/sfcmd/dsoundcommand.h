#ifndef DSOUNDCOMMAND_H
#define DSOUNDCOMMAND_H

#include <QString>
#include "sfcommand.h"

class DsoundCommand : public SFCommand
{
public:
    DsoundCommand();
    virtual ~DsoundCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DSOUNDCOMMAND_H

