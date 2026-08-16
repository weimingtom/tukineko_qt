#ifndef UNDERLINECOMMAND_H
#define UNDERLINECOMMAND_H

#include <QString>
#include "sfcommand.h"

class UnderlineCommand : public SFCommand
{
public:
    UnderlineCommand();
    virtual ~UnderlineCommand();

    bool check(const QString& str);
    void execute();
};

#endif // UNDERLINECOMMAND_H

