#include "lookbackbuttoncommand.h"
#include "nscripter.h"
#include <iostream>

LookbackbuttonCommand::LookbackbuttonCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool LookbackbuttonCommand::check(const QString &str)
{
    return checkCommand(str, "lookbackbutton");
}

void LookbackbuttonCommand::execute()
{
    debug("[SFCommand] lookbackbutton");

    std::cerr << "not implement: lookbackbutton" << std::endl;
}
