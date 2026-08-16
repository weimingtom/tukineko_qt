#include "rndcommand.h"

RndCommand::RndCommand()
{

}

RndCommand::~RndCommand()
{

}

bool RndCommand::check(const QString& str)
{
    return str.startsWith("rnd ");
}

void RndCommand::execute()
{

}
