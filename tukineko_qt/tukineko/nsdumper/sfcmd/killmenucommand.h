#ifndef KILLMENUCOMMAND_H
#define KILLMENUCOMMAND_H

#include <QString>
#include "sfcommand.h"

class KillmenuCommand : public SFCommand
{
public:
    KillmenuCommand();
    virtual ~KillmenuCommand();

    bool check(const QString& str);
    void execute();
};

#endif // KILLMENUCOMMAND_H
