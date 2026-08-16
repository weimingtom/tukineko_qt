#ifndef GLOBALONCOMMAND_H
#define GLOBALONCOMMAND_H

#include <QString>
#include "sfcommand.h"

class GlobalonCommand : public SFCommand
{
public:
    GlobalonCommand();
    virtual ~GlobalonCommand();

    bool check(const QString& str);
    void execute();
};

#endif // GLOBALONCOMMAND_H
