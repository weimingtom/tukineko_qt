#include "SaveoffCommand.h"
#include <QDebug>

SaveoffCommand::SaveoffCommand()
{
}

bool SaveoffCommand::check(const QString &str)
{
    return checkCommand(str, "saveoff");
}

void SaveoffCommand::execute()
{
    debug("[FECommand] saveoff");

    qCritical() << "not implement: saveoff";
}
