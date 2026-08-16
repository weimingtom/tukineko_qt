#include "bgaliacommand.h"

BgaliaCommand::BgaliaCommand()
{
}

BgaliaCommand::~BgaliaCommand()
{
}

bool BgaliaCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void BgaliaCommand::execute()
{
}
