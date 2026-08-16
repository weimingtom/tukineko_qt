#ifndef TRANSMODECOMMAND_H
#define TRANSMODECOMMAND_H

#include <QString>
#include "sfcommand.h"

class TransmodeCommand : public SFCommand
{
public:
    TransmodeCommand();
    virtual ~TransmodeCommand();

    bool check(const QString& str);
    void execute();
};

#endif // TRANSMODECOMMAND_H

