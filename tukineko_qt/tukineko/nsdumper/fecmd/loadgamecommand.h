#ifndef LOADGAMECOMMAND_H
#define LOADGAMECOMMAND_H

#include <QString>
#include "fecommand.h"

class LoadgameCommand : public FECommand
{
public:
    LoadgameCommand();
    virtual ~LoadgameCommand();
    bool check(const QString& str);
    void execute();
};

#endif // LOADGAMECOMMAND_H
