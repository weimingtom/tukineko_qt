#ifndef SAVEONCOMMAND_H
#define SAVEONCOMMAND_H

#include <QString>
#include "fecommand.h"

class SaveonCommand : public FECommand
{
public:
    SaveonCommand();
    virtual ~SaveonCommand();

    bool check(const QString& str);
    void execute();
};


#endif // SAVEONCOMMAND_H
