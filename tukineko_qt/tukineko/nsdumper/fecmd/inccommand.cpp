#include "inccommand.h"

IncCommand::IncCommand()
{

}

IncCommand::~IncCommand()
{

}

bool IncCommand::check(const QString& str)
{
    return str.startsWith("inc ");
}

void IncCommand::execute()
{

}
