#include "jumpbcommand.h"

JumpbCommand::JumpbCommand()
{

}

JumpbCommand::~JumpbCommand()
{

}

bool JumpbCommand::check(const QString& str)
{
    return str.startsWith("jumpb ");
}

void JumpbCommand::execute()
{

}
