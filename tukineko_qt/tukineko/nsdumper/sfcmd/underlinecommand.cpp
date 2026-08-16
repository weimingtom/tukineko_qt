#include "underlinecommand.h"

UnderlineCommand::UnderlineCommand()
{
}

UnderlineCommand::~UnderlineCommand()
{
}

bool UnderlineCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void UnderlineCommand::execute()
{
}
