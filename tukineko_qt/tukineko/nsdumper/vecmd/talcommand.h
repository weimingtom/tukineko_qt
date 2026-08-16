#ifndef TALCOMMAND_H
#define TALCOMMAND_H

#include <QString>
#include "vecommand.h"

class TalCommand : public VECommand
{
public:
    TalCommand();
    virtual ~TalCommand();

    bool check(const QString& str);
    void execute();
};

#endif // TALCOMMAND_H
