#include "SetcursorCommand.h"
#include <QDebug>

SetcursorCommand::SetcursorCommand()
{
}

bool SetcursorCommand::check(const QString &str)
{
    return checkCommand(str, "setcursor");
}

void SetcursorCommand::execute()
{
    debug("[SECommand] setcursor");

    qCritical() << "not implement: setcursor";
}
