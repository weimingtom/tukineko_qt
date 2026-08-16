#ifndef WAVECOMMAND_H
#define WAVECOMMAND_H

#include <QString>
#include "vecommand.h"

class WaveCommand : public VECommand
{
public:
    WaveCommand();
    virtual ~WaveCommand();

    bool check(const QString& str);
    void execute();
};

#endif // WAVECOMMAND_H
