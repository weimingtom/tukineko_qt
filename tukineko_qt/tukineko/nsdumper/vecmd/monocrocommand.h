#ifndef MONOCROCOMMAND_H
#define MONOCROCOMMAND_H

#include <QString>
#include "vecommand.h"

class MonocroCommand : public VECommand
{
public:
    MonocroCommand();
    virtual ~MonocroCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MONOCROCOMMAND_H
