#ifndef FILELOGCOMMAND_H
#define FILELOGCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class FilelogCommand : public SFCommand
{
public:
    FilelogCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // FILELOGCOMMAND_H
