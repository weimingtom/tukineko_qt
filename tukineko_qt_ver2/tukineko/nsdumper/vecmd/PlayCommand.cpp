#include "PlayCommand.h"
#include "NScripter.h"
#include <QDebug>

PlayCommand::PlayCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

PlayCommand::~PlayCommand()
{
}

bool PlayCommand::check(const QString &str)
{
    return checkCommand(str, "play");
}

void PlayCommand::execute()
{
    debug("[VECommand] play");

    qCritical() << "not implement: play";
}
