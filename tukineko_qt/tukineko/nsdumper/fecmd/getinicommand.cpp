#include "getinicommand.h"

GetiniCommand::GetiniCommand()
{

}

GetiniCommand::~GetiniCommand()
{

}

bool GetiniCommand::check(const QString& str)
{
    return str.startsWith("getini ");
}

void GetiniCommand::execute()
{

}
