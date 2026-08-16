#include "dwaveloopcommand.h"

DwaveloopCommand::DwaveloopCommand()
{
}

DwaveloopCommand::~DwaveloopCommand()
{
}

bool DwaveloopCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void DwaveloopCommand::execute()
{
}
