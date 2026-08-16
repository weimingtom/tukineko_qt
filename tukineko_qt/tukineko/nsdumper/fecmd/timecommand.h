#ifndef TIMECOMMAND_H
#define TIMECOMMAND_H

#include <QString>
#include "fecommand.h"

class TimeCommand : public FECommand
{
public:
    TimeCommand();
    virtual ~TimeCommand();

    bool check(const QString& str);
    void execute();
};

#endif // TIMECOMMAND_H
