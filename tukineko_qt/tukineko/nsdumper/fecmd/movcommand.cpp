#include "movcommand.h"

MovCommand::MovCommand()
{

}

MovCommand::~MovCommand()
{

}

bool MovCommand::check(const QString& str)
{
    return str.startsWith("mov ");
}

void MovCommand::execute()
{

}
