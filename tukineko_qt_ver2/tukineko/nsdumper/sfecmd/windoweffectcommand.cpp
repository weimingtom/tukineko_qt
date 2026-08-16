#include "windoweffectcommand.h"
#include "nscripter.h"
#include "nseffect.h"

WindoweffectCommand::WindoweffectCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool WindoweffectCommand::check(const QString &str)
{
    return checkCommand(str, "windoweffect");
}

void WindoweffectCommand::execute()
{
    debug("[SFECommand] windoweffect");

    switch (ns->parseArgs(true)) {
    case 1:
        ns->nd->effect["window"] =
                NsEffect(ns->nd->evalNum(ns->getArg(0)));
        break;

    case 2:
        ns->nd->effect["window"] =
                NsEffect(ns->nd->evalNum(ns->getArg(0)), ns->nd->evalNum(ns->getArg(1)));
        break;

    case 3:
        ns->nd->effect["window"] =
                NsEffect(ns->nd->evalNum(ns->getArg(0)), ns->nd->evalNum(ns->getArg(1)), ns->nd->evalStr(ns->getArg(2)));
        break;

    default:
        ns->error("windoweffect");
        break;
    }
}
