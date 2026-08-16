#ifndef MODCOMMAND_H
#define MODCOMMAND_H

#include <QString>
#include "fecommand.h"

class ModCommand : public FECommand
{
public:
    ModCommand();
    virtual ~ModCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MODCOMMAND_H
