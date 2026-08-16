#include "skipcommand.h"

SkipCommand::SkipCommand()
{

}

SkipCommand::~SkipCommand()
{

}

bool SkipCommand::check(const QString& str)
{
    return str.startsWith("skip ");
}

void SkipCommand::execute()
{

}
