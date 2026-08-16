#include "rnd2command.h"

Rnd2Command::Rnd2Command()
{

}

Rnd2Command::~Rnd2Command()
{

}

bool Rnd2Command::check(const QString& str)
{
    return str.startsWith("rnd2 ");
}

void Rnd2Command::execute()
{

}
