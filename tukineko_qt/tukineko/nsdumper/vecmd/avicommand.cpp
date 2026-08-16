#include "avicommand.h"

AviCommand::AviCommand()
{
}

AviCommand::~AviCommand()
{
}

bool AviCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void AviCommand::execute()
{
}
