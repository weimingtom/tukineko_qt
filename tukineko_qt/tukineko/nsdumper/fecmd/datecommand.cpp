#include "datecommand.h"

DateCommand::DateCommand()
{
}

DateCommand::~DateCommand()
{
}

bool DateCommand::check(const QString& str)
{
    return str.startsWith("date ");
}

void DateCommand::execute()
{
}
