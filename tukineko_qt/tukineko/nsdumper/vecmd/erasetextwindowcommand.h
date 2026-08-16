#ifndef ERASETEXTWINDOWCOMMAND_H
#define ERASETEXTWINDOWCOMMAND_H

#include <QString>
#include "vecommand.h"

class ErasetextwindowCommand : public VECommand
{
public:
    ErasetextwindowCommand();
    virtual ~ErasetextwindowCommand();

    bool check(const QString& str);
    void execute();
};

#endif // ERASETEXTWINDOWCOMMAND_H

