#ifndef PLAYCOMMAND_H
#define PLAYCOMMAND_H

#include <QString>
#include "vecommand.h"

class PlayCommand : public VECommand
{
public:
    PlayCommand();
    virtual ~PlayCommand();

    bool check(const QString& str);
    void execute();
};

#endif // PLAYCOMMAND_H
