#ifndef DECCOMMAND_H
#define DECCOMMAND_H

#include <QString>
#include "fecommand.h"

class DecCommand : public FECommand
{
public:
    DecCommand();
    virtual ~DecCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DECCOMMAND_H
