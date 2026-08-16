#ifndef SELNUMCOMMAND_H
#define SELNUMCOMMAND_H

#include "ecommand.h"

class SelnumCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // SELNUMCOMMAND_H
