#ifndef OFSCPYCOMMAND_H
#define OFSCPYCOMMAND_H

#include <QString>
#include "vecommand.h"

class OfscpyCommand : public VECommand
{
public:
    OfscpyCommand();
    virtual ~OfscpyCommand();

    bool check(const QString& str);
    void execute();
};

#endif // OFSCPYCOMMAND_H
