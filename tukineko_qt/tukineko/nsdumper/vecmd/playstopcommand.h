#ifndef PLAYSTOPCOMMAND_H
#define PLAYSTOPCOMMAND_H

#include <QString>
#include "vecommand.h"

class PlaystopCommand : public VECommand
{
public:
    PlaystopCommand();
    virtual ~PlaystopCommand();

    bool check(const QString& str);
    void execute();
};

#endif // PLAYSTOPCOMMAND_H
