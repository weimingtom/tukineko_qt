#include "bgcommand.h"

BgCommand::BgCommand()
{
}

BgCommand::~BgCommand()
{
}

bool BgCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void BgCommand::execute()
{
}

