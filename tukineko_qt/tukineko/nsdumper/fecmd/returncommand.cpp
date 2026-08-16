#include "returncommand.h"

ReturnCommand::ReturnCommand()
{

}

ReturnCommand::~ReturnCommand()
{

}

bool ReturnCommand::check(const QString& str)
{
    return str == "return";
}

void ReturnCommand::execute()
{

}
