#ifndef SELGOSUBCOMMAND_H
#define SELGOSUBCOMMAND_H

#include "ecommand.h"

class SelgosubCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // SELGOSUBCOMMAND_H
