#ifndef SELGOSUBCOMMAND_H
#define SELGOSUBCOMMAND_H

#include "ecommand.h"

class SelgosubCommand : public ECommand
{
public:
    SelgosubCommand();
    virtual ~SelgosubCommand();
    bool check(const QString& str);
    void execute();
};

#endif // SELGOSUBCOMMAND_H
