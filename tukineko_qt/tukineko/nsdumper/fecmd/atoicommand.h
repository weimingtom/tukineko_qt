#ifndef ATOCOMMAND_H
#define ATOCOMMAND_H

#include <QString>
#include "fecommand.h"

class AtoiCommand : public FECommand
{
public:
    AtoiCommand();
    virtual ~AtoiCommand();

    bool check(const QString& str);
    void execute();
};

#endif // ATOCOMMAND_H
