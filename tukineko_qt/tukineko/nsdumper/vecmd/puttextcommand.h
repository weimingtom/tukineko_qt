#ifndef PUTTEXTCOMMAND_H
#define PUTTEXTCOMMAND_H

#include <QString>
#include "vecommand.h"

class PuttextCommand : public VECommand
{
public:
    PuttextCommand();
    virtual ~PuttextCommand();

    bool check(const QString& str);
    void execute();
};

#endif // PUTTEXTCOMMAND_H
