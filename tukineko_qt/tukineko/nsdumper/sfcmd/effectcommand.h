#ifndef EFFECTCOMMAND_H
#define EFFECTCOMMAND_H

#include <QString>
#include "sfcommand.h"

class EffectCommand : public SFCommand
{
public:
    EffectCommand();
    virtual ~EffectCommand();

    bool check(const QString& str);
    void execute();
};

#endif // EFFECTCOMMAND_H

