#ifndef QUAKEYCOMMAND_H
#define QUAKEYCOMMAND_H

#include <QString>
#include "vecommand.h"

class QuakeyCommand : public VECommand
{
public:
    QuakeyCommand();
    virtual ~QuakeyCommand();

    bool check(const QString& str);
    void execute();
};

#endif // QUAKEYCOMMAND_H

