#include "mesboxcommand.h"

MesboxCommand::MesboxCommand()
{
    ns = NScripter::getInstance();
}

MesboxCommand::~MesboxCommand()
{
}

bool MesboxCommand::check(const QString& str)
{
    return checkCommand(str, "mesbox");
}

void MesboxCommand::execute()
{
    debug("[VFECommand] mesbox");

    ns->error("mesbox");
}


