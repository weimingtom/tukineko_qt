#include "negacommand.h"

NegaCommand::NegaCommand()
{
}

NegaCommand::~NegaCommand()
{
}

bool NegaCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void NegaCommand::execute()
{
}
