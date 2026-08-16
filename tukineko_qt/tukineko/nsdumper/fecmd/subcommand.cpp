#include "subcommand.h"

SubCommand::SubCommand()
{

}

SubCommand::~SubCommand()
{

}

bool SubCommand::check(const QString& str)
{
    return str.startsWith("sub ");
}

void SubCommand::execute()
{

}
