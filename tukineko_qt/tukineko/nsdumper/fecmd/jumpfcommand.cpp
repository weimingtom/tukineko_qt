#include "jumpfcommand.h"

JumpfCommand::JumpfCommand()
{

}

JumpfCommand::~JumpfCommand()
{

}

bool JumpfCommand::check(const QString& str)
{
    return str.startsWith("jumpf ");
}

void JumpfCommand::execute()
{

}
