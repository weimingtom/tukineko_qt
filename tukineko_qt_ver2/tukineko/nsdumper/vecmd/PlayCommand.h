#ifndef PLAYCOMMAND_H
#define PLAYCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class PlayCommand : public VECommand
{
public:
    PlayCommand();
    virtual ~PlayCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // PLAYCOMMAND_H
