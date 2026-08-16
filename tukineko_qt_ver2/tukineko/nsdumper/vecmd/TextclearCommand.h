#ifndef TEXTCLEARCOMMAND_H
#define TEXTCLEARCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class TextclearCommand : public VECommand
{
public:
    TextclearCommand();
    virtual ~TextclearCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // TEXTCLEARCOMMAND_H
