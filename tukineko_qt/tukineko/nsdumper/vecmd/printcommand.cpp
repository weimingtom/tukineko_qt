#include "printcommand.h"

PrintCommand::PrintCommand()
{
}

PrintCommand::~PrintCommand()
{
}

bool PrintCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void PrintCommand::execute()
{
}
