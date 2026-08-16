#include "getregcommand.h"

GetregCommand::GetregCommand()
{

}

GetregCommand::~GetregCommand()
{

}

bool GetregCommand::check(const QString& str)
{
    return str.startsWith("getreg ");
}

void GetregCommand::execute()
{

}
