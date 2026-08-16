#include "dwavecommand.h"

DwaveCommand::DwaveCommand()
{
}

DwaveCommand::~DwaveCommand()
{
}

bool DwaveCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void DwaveCommand::execute()
{
}
