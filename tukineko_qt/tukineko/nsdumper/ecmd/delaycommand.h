#ifndef DELAYCOMMAND_H
#define DELAYCOMMAND_H

#include "ecommand.h"

class DelayCommand : public ECommand
{
public:
    DelayCommand();
    virtual ~DelayCommand();
    bool check(const QString& str);
    void execute();
};

#endif // DELAYCOMMAND_H
