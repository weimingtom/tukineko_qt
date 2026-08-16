#ifndef ARCCOMMAND_H
#define ARCCOMMAND_H

#include <QString>
#include "sfcommand.h"

class ArcCommand : public SFCommand
{
public:
    ArcCommand();
    virtual ~ArcCommand();

    bool check(const QString& str);
    void execute();
};

#endif // ARCCOMMAND_H

