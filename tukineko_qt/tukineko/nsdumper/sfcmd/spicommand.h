#ifndef SPICOMMAND_H
#define SPICOMMAND_H

#include <QString>
#include "sfcommand.h"

class SpiCommand : public SFCommand
{
public:
    SpiCommand();
    virtual ~SpiCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SPICOMMAND_H
