#ifndef TEXTOFFCOMMAND_H
#define TEXTOFFCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class TextoffCommand : public VECommand
{
public:
    TextoffCommand();
    virtual ~TextoffCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // TEXTOFFCOMMAND_H
