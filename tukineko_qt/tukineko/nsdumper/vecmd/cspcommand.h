#ifndef CSPCOMMAND_H
#define CSPCOMMAND_H

#include <QString>
#include "vecommand.h"

class CspCommand : public VECommand
{
public:
    CspCommand();
    virtual ~CspCommand();

    bool check(const QString& str);
    void execute();
};

#endif // CSPCOMMAND_H

