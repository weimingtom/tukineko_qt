#include "PrintCommand.h"
#include "NScripter.h"

PrintCommand::PrintCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

PrintCommand::~PrintCommand()
{
}

bool PrintCommand::check(const QString &str)
{
    return checkCommand(str, "print");
}

void PrintCommand::execute()
{
    debug("[VECommand] print");

    if (ns->parseArgs(true) < 1) {
        ns->error("print");
    } else {
        ns->tn->paintB();
        ns->makeLineRest(1);
    }
}
