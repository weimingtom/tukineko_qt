#ifndef SELNUMCOMMAND_H
#define SELNUMCOMMAND_H

#include "ecommand.h"

class SelnumCommand : public ECommand
{
public:
    SelnumCommand();
    virtual ~SelnumCommand();
    bool check(const QString& str);
    void execute();
};

#endif // SELNUMCOMMAND_H
