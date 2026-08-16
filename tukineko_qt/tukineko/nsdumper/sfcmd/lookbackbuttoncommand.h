#ifndef LOOKBACKBUTTONCOMMAND_H
#define LOOKBACKBUTTONCOMMAND_H

#include <QString>
#include "sfcommand.h"

class LookbackbuttonCommand : public SFCommand
{
public:
    LookbackbuttonCommand();
    virtual ~LookbackbuttonCommand();

    bool check(const QString& str);
    void execute();
};

#endif // LOOKBACKBUTTONCOMMAND_H

