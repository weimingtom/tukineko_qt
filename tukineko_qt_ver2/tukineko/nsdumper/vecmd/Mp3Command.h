#ifndef MP3COMMAND_H
#define MP3COMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class Mp3Command : public VECommand
{
public:
    Mp3Command();
    virtual ~Mp3Command();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MP3COMMAND_H
