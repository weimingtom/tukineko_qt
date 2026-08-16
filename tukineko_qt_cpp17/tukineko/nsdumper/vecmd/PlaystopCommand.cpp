#include "PlaystopCommand.h"
#include "NScripter.h"
#include <QDebug>

namespace tukineko {

PlaystopCommand::PlaystopCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

PlaystopCommand::~PlaystopCommand()
{
}

bool PlaystopCommand::check(const QString &str)
{
    return str.startsWith("playstop");
}

void PlaystopCommand::execute()
{
    debug("[VECommand] playstop");

    ns->setMsRest();
    qCritical() << "not implement: playstop";
}

}
