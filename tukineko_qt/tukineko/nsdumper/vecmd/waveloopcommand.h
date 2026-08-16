#ifndef WAVELOOPCOMMAND_H
#define WAVELOOPCOMMAND_H

#include <QString>
#include "vecommand.h"

class WaveloopCommand : public VECommand
{
public:
    WaveloopCommand();
    virtual ~WaveloopCommand();

    bool check(const QString& str);
    void execute();
};

#endif // WAVELOOPCOMMAND_H
