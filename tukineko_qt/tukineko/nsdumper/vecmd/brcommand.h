#ifndef BRCOMMAND_H
#define BRCOMMAND_H

#include <QString>
#include "vecommand.h"

class BrCommand : public VECommand
{
public:
    BrCommand();
    virtual ~BrCommand();

    bool check(const QString& str);
    void execute();
};

#endif // BRCOMMAND_H
