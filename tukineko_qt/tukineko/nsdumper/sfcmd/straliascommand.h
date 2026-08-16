#ifndef STRALIASCOMMAND_H
#define STRALIASCOMMAND_H

#include <QString>
#include "sfcommand.h"

class StraliasCommand : public SFCommand
{
public:
    StraliasCommand();
    virtual ~StraliasCommand();

    bool check(const QString& str);
    void execute();
};

#endif // STRALIASCOMMAND_H
