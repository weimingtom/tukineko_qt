#ifndef PLAYONCECOMMAND_H
#define PLAYONCECOMMAND_H

#include <QString>
#include "vecommand.h"

class PlayonceCommand : public VECommand
{
public:
    PlayonceCommand();
    virtual ~PlayonceCommand();

    bool check(const QString& str);
    void execute();
};

#endif // PLAYONCECOMMAND_H
