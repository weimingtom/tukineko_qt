#ifndef BLTCOMMAND_H
#define BLTCOMMAND_H

#include <QString>
#include "vecommand.h"

class BltCommand : public VECommand
{
public:
    BltCommand();
    virtual ~BltCommand();

    bool check(const QString& str);
    void execute();
};

#endif // BLTCOMMAND_H
