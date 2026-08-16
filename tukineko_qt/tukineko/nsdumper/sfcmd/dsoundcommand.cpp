#include "dsoundcommand.h"

DsoundCommand::DsoundCommand()
{
}

DsoundCommand::~DsoundCommand()
{
}

bool DsoundCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void DsoundCommand::execute()
{
}
