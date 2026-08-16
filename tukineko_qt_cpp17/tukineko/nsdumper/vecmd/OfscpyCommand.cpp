#include "OfscpyCommand.h"
#include "NScripter.h"
#include <QDebug>

namespace tukineko {

OfscpyCommand::OfscpyCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

OfscpyCommand::~OfscpyCommand()
{
}

bool OfscpyCommand::check(const QString &str)
{
    return checkCommand(str, "ofscpy");
}

void OfscpyCommand::execute()
{
    debug("[VECommand] ofscpy");

    ns->setMsRest();
    qCritical() << "not implement: cfscpy";
}

}
