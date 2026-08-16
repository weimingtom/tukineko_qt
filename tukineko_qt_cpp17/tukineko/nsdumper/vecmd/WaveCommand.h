#ifndef WAVECOMMAND_H
#define WAVECOMMAND_H

#include "VECommand.h"

namespace tukineko {

class WaveCommand : public VECommand
{
public:
    WaveCommand();
    virtual ~WaveCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;
};

}

#endif // WAVECOMMAND_H
