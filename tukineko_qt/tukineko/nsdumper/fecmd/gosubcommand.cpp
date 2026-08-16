#include "gosubcommand.h"

GosubCommand::GosubCommand()
{

}

GosubCommand::~GosubCommand()
{

}

bool GosubCommand::check(const QString& str)
{
    return str.startsWith("gosub ");
}

void GosubCommand::execute()
{

}
