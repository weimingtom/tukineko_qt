#include "rlookbackcommand.h"

RlookbackCommand::RlookbackCommand()
{
}

RlookbackCommand::~RlookbackCommand()
{
}

bool RlookbackCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void RlookbackCommand::execute()
{
}
