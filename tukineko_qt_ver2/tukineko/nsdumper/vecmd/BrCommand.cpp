#include "BrCommand.h"
#include "NScripter.h"

BrCommand::BrCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

BrCommand::~BrCommand()
{
}

bool BrCommand::check(const QString &str)
{
    return str.startsWith("br");
}

void BrCommand::execute()
{
    debug("[VECommand] br");

    ns->setMsRest();
    ns->tn->putMess(ns->nd->text, "", &ns->nd->textcolor, true, false);
    if (!ns->nd->fadeFlag) {
        ns->tn->paintB();
    } else {
        ns->tn->paintF();
    }
}
