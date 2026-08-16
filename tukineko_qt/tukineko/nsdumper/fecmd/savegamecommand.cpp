#include "savegamecommand.h"

SavegameCommand::SavegameCommand()
{

}

SavegameCommand::~SavegameCommand()
{

}

bool SavegameCommand::check(const QString& str)
{
    return str.startsWith("savegame ");
}

void SavegameCommand::execute()
{

}
