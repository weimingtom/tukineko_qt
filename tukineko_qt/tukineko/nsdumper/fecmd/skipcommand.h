#ifndef SKIPCOMMAND_H
#define SKIPCOMMAND_H

#include <QString>
#include "fecommand.h"

class SkipCommand : public FECommand
{
public:
    SkipCommand();
    virtual ~SkipCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SKIPCOMMAND_H
