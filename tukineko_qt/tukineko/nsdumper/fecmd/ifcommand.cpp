#include "ifcommand.h"

IfCommand::IfCommand()
{

}

IfCommand::~IfCommand()
{

}

bool IfCommand::check(const QString& str)
{
    return str.startsWith("if ");
}

void IfCommand::execute()
{

}
