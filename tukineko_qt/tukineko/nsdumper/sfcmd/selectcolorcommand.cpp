#include "selectcolorcommand.h"

SelectcolorCommand::SelectcolorCommand()
{
}

SelectcolorCommand::~SelectcolorCommand()
{
}

bool SelectcolorCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void SelectcolorCommand::execute()
{
}
