#include "defaultfontcommand.h"

DefaultfontCommand::DefaultfontCommand()
{
}

DefaultfontCommand::~DefaultfontCommand()
{
}

bool DefaultfontCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void DefaultfontCommand::execute()
{
}
