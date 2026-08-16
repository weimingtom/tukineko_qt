#include "gamecommand.h"

GameCommand::GameCommand()
{
    m_cmdName = "game";
}

GameCommand::~GameCommand()
{
}

bool GameCommand::check(const QString& str)
{
    return str.startsWith("game ");
}

void GameCommand::execute()
{
}
