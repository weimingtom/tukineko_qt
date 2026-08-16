#ifndef WAVELOOPCOMMAND_H
#define WAVELOOPCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class WaveloopCommand : public VECommand
{
public:
    WaveloopCommand();
    virtual ~WaveloopCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // WAVELOOPCOMMAND_H
