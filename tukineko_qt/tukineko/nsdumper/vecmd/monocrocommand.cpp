#include "monocrocommand.h"

MonocroCommand::MonocroCommand()
{
}

MonocroCommand::~MonocroCommand()
{
}

bool MonocroCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MonocroCommand::execute()
{
}
