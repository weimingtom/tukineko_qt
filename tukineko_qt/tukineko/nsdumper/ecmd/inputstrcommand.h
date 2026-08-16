#ifndef INPUTSTRCOMMAND_H
#define INPUTSTRCOMMAND_H

#include "ecommand.h"

class InputstrCommand : public ECommand
{
public:
    InputstrCommand();
    virtual ~InputstrCommand();
    bool check(const QString& str);
    void execute();
};

#endif // INPUTSTRCOMMAND_H
