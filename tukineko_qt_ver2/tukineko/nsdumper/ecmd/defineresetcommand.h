#ifndef DEFINERESETCOMMAND_H
#define DEFINERESETCOMMAND_H

#include "ecommand.h"

class DefineresetCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // DEFINERESETCOMMAND_H
