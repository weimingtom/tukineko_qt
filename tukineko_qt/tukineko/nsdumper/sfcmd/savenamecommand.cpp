#include "savenamecommand.h"

SavenameCommand::SavenameCommand()
{
}

SavenameCommand::~SavenameCommand()
{
}

bool SavenameCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void SavenameCommand::execute()
{
}
