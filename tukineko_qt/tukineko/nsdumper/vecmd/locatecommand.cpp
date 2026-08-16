#include "locatecommand.h"

LocateCommand::LocateCommand()
{
}

LocateCommand::~LocateCommand()
{
}

bool LocateCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void LocateCommand::execute()
{
}
