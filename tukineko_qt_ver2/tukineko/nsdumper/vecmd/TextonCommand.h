#ifndef TEXTONCOMMAND_H
#define TEXTONCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class TextonCommand : public VECommand
{
public:
    TextonCommand();
    virtual ~TextonCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // TEXTONCOMMAND_H
