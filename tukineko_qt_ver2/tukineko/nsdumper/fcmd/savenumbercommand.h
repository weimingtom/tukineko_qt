#ifndef SAVENUMBERCOMMAND_H
#define SAVENUMBERCOMMAND_H

#include "fcommand.h"

class SavenumberCommand : public FCommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // SAVENUMBERCOMMAND_H
