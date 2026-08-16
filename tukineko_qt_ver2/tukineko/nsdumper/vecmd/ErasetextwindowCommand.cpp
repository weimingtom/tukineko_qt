#include "ErasetextwindowCommand.h"
#include "NScripter.h"

ErasetextwindowCommand::ErasetextwindowCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

ErasetextwindowCommand::~ErasetextwindowCommand()
{
}

bool ErasetextwindowCommand::check(const QString &str)
{
    return str.startsWith("erasetextwindow");
}

void ErasetextwindowCommand::execute()
{
    debug("[VECommand] erasetextwindow");

    ns->error("erasetextwindow");
}
