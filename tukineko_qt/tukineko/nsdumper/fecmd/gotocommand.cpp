#include "gotocommand.h"

GotoCommand::GotoCommand()
{

}

GotoCommand::~GotoCommand()
{

}

bool GotoCommand::check(const QString& str)
{
    return str.startsWith("gosub ");
}

void GotoCommand::execute()
{
}
