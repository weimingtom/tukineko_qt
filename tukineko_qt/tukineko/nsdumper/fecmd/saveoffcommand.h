#ifndef SAVEOFFCOMMAND_H
#define SAVEOFFCOMMAND_H

#include <QString>
#include "fecommand.h"

class SaveoffCommand : public FECommand
{
public:
    SaveoffCommand();
    virtual ~SaveoffCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SAVEOFFCOMMAND_H
