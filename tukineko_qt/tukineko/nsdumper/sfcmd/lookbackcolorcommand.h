#ifndef LOOKBACKCOLORCOMMAND_H
#define LOOKBACKCOLORCOMMAND_H

#include <QString>
#include "sfcommand.h"

class LookbackcolorCommand : public SFCommand
{
public:
    LookbackcolorCommand();
    virtual ~LookbackcolorCommand();

    bool check(const QString& str);
    void execute();
};

#endif // LOOKBACKCOLORCOMMAND_H

