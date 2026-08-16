#ifndef GOSUBCOMMAND_H
#define GOSUBCOMMAND_H

#include <QString>
#include "fecommand.h"

class GosubCommand : public FECommand
{
public:
    GosubCommand();
    virtual ~GosubCommand();

    bool check(const QString& str);
    void execute();
};

#endif // GOSUBCOMMAND_H
