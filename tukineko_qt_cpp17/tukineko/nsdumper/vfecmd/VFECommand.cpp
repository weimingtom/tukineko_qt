#include "VFECommand.h"

namespace tukineko {

VFECommand::VFECommand()
{
}

VFECommand::~VFECommand()
{
}

bool VFECommand::check(const QString &)
{
    return false;
}

void VFECommand::execute()
{
}

bool VFECommand::checkCommand(const QString &paramString1, const QString &paramString2)
{
    if (paramString1 == paramString2) {
        return true;
    }
    if (paramString1.length() > paramString2.length() &&
        paramString1.startsWith(paramString2) &&
        (paramString1[paramString2.length()] == ' ' || paramString1[paramString2.length()] == '\t')) {
        return true;
    }
    return false;
}

void VFECommand::debug(const QString &str)
{
    qDebug() << str;
}

}
