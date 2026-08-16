#ifndef DEFSPEEDCOMMAND_H
#define DEFSPEEDCOMMAND_H

#include <QString>
#include "sfcommand.h"

class DefSpeedCommand : public SFCommand
{
public:
    DefSpeedCommand();
    virtual ~DefSpeedCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DEFSPEEDCOMMAND_H
