#include "timecommand.h"

TimeCommand::TimeCommand()
{

}

TimeCommand::~TimeCommand()
{

}

bool TimeCommand::check(const QString& str)
{
    return str.startsWith("time ");
}

void TimeCommand::execute()
{

}
