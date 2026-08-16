#ifndef MONOCROCOMMAND_H
#define MONOCROCOMMAND_H

#include "VECommand.h"

class MonocroCommand : public VECommand
{
public:
    MonocroCommand();
    virtual ~MonocroCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;
};

#endif // MONOCROCOMMAND_H
