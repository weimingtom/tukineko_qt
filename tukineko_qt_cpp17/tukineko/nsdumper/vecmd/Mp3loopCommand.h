#ifndef MP3LOOPCOMMAND_H
#define MP3LOOPCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class Mp3loopCommand : public VECommand
{
public:
    Mp3loopCommand();
    virtual ~Mp3loopCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MP3LOOPCOMMAND_H
