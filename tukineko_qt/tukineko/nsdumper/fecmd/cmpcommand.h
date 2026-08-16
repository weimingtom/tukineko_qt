#ifndef CMPCOMMAND_H
#define CMPCOMMAND_H

#include <QString>
#include "fecommand.h"

class CmpCommand : public FECommand
{
public:
    CmpCommand();
    virtual ~CmpCommand();

    bool check(const QString& str);
    void execute();
};

#endif // CMPCOMMAND_H
