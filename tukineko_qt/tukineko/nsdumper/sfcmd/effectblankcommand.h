#ifndef EFFECTBLANKCOMMAND_H
#define EFFECTBLANKCOMMAND_H

#include <QString>
#include "sfcommand.h"

class EffectblankCommand : public SFCommand
{
public:
    EffectblankCommand();
    virtual ~EffectblankCommand();

    bool check(const QString& str);
    void execute();
};

#endif // EFFECTBLANKCOMMAND_H
