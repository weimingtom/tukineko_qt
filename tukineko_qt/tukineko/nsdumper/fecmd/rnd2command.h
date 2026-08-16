#ifndef RND2COMMAND_H
#define RND2COMMAND_H

#include <QString>
#include "fecommand.h"

class Rnd2Command : public FECommand
{
public:
    Rnd2Command();
    virtual ~Rnd2Command();

    bool check(const QString& str);
    void execute();
};

#endif // RND2COMMAND_H
