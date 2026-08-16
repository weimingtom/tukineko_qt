#include "clickstrcommand.h"

ClickstrCommand::ClickstrCommand()
{
}

ClickstrCommand::~ClickstrCommand()
{
}

bool ClickstrCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void ClickstrCommand::execute()
{
}
