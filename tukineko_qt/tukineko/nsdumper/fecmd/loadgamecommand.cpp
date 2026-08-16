#include "loadgamecommand.h"

LoadgameCommand::LoadgameCommand()
{

}

LoadgameCommand::~LoadgameCommand()
{

}

bool LoadgameCommand::check(const QString& str)
{
    return str.startsWith("loadgame ");
}

void LoadgameCommand::execute()
{

}
