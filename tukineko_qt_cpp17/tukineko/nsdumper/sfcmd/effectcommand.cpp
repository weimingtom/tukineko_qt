#include "effectcommand.h"
#include "nscripter.h"
#include "nseffect.h"

EffectCommand::EffectCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool EffectCommand::check(const QString &str)
{
    return checkCommand(str, "effect");
}

void EffectCommand::execute()
{
    debug("[SFCommand] effect");

    switch (ns->parseArgs(true)) {
    case 2:
        ns->nd->effect.insert(
                QString::number(ns->nd->evalNum(ns->getArg(0))),
                NsEffect(ns->nd->evalNum(ns->getArg(1))));
        break;

    case 3:
        ns->nd->effect.insert(
                QString::number(ns->nd->evalNum(ns->getArg(0))),
                NsEffect(ns->nd->evalNum(ns->getArg(1)),
                        ns->nd->evalNum(ns->getArg(2))));
        break;

    case 4:
        ns->nd->effect.insert(
                QString::number(ns->nd->evalNum(ns->getArg(0))),
                NsEffect(ns->nd->evalNum(ns->getArg(1)),
                        ns->nd->evalNum(ns->getArg(2)),
                        ns->nd->evalStr(ns->getArg(3))));
        break;

    default:
        ns->error("effect");
        break;
    }
}
