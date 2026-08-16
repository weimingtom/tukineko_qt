#ifndef AVICOMMAND_H
#define AVICOMMAND_H

#include <QString>
#include "vecommand.h"

class AviCommand : public VECommand
{
public:
    AviCommand();
    virtual ~AviCommand();

    bool check(const QString& str);
    void execute();
};

#endif // AVICOMMAND_H
