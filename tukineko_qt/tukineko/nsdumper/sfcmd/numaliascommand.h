#ifndef NUMALIASCOMMAND_H
#define NUMALIASCOMMAND_H

#include <QString>
#include "sfcommand.h"

class NumaliasCommand : public SFCommand
{
public:
    NumaliasCommand();
    virtual ~NumaliasCommand();

    bool check(const QString& str);
    void execute();
};

#endif // NUMALIASCOMMAND_H
