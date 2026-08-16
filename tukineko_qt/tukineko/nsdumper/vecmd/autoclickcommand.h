#ifndef AUTOCLICKCOMMAND_H
#define AUTOCLICKCOMMAND_H

#include <QString>
#include "vecommand.h"

class AutoclickCommand : public VECommand
{
public:
    AutoclickCommand();
    virtual ~AutoclickCommand();

    bool check(const QString& str);
    void execute();
};

#endif // AUTOCLICKCOMMAND_H

