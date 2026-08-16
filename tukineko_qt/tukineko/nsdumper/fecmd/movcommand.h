#ifndef MOVCOMMAND_H
#define MOVCOMMAND_H

#include <QString>
#include "fecommand.h"

class MovCommand : public FECommand
{
public:
    MovCommand();
    virtual ~MovCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MOVCOMMAND_H
