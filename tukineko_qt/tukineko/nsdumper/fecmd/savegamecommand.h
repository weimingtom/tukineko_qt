#ifndef SAVEGAMECOMMAND_H
#define SAVEGAMECOMMAND_H

#include <QString>
#include "fecommand.h"

class SavegameCommand : public FECommand
{
public:
    SavegameCommand();
    virtual ~SavegameCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SAVEGAMECOMMAND_H
