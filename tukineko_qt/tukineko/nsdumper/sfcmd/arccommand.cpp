#include "arccommand.h"

ArcCommand::ArcCommand()
{
}

ArcCommand::~ArcCommand()
{
}

bool ArcCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void ArcCommand::execute()
{
}
