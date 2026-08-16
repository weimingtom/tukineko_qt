#ifndef ENDCOMMAND_H
#define ENDCOMMAND_H

#include <QString>
#include "fecommand.h"

class EndCommand : public FECommand
{
public:
    EndCommand();
    virtual ~EndCommand();

    bool check(const QString& str);
    void execute();
};

#endif // ENDCOMMAND_H
