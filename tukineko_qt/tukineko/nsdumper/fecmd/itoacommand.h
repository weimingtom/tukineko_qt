#ifndef ITOACOMMAND_H
#define ITOACOMMAND_H

#include <QString>
#include "fecommand.h"

class ItoaCommand : public FECommand
{
public:
    ItoaCommand();
    virtual ~ItoaCommand();

    bool check(const QString& str);
    void execute();
};

#endif // ITOACOMMAND_H
