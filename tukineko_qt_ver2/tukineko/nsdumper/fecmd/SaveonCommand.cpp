#include "SaveonCommand.h"
#include <QDebug>

SaveonCommand::SaveonCommand()
{
}

bool SaveonCommand::check(const QString &str)
{
    return checkCommand(str, "saveon");
}

void SaveonCommand::execute()
{
    debug("[FECommand] saveon");

    qCritical() << "not implement: saveon";
}
