#ifndef SAVENUMBERCOMMAND_H
#define SAVENUMBERCOMMAND_H

#include "fcommand.h"

class SavenumberCommand : public FCommand
{
public:
    SavenumberCommand();
    virtual ~SavenumberCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SAVENUMBERCOMMAND_H
