#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include <QString>
#include "vecommand.h"

class PrintCommand : public VECommand
{
public:
    PrintCommand();
    virtual ~PrintCommand();

    bool check(const QString& str);
    void execute();
};

#endif // PRINTCOMMAND_H

