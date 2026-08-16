#include "windoweffectcommand.h"

WindoweffectCommand::WindoweffectCommand()
{
    ns = NScripter::getInstance();
}

WindoweffectCommand::~WindoweffectCommand()
{
}

bool WindoweffectCommand::check(const QString& str)
{
    return checkCommand(str, "windoweffect");
}

void WindoweffectCommand::execute()
{
    debug("[SFECommand] windoweffect");

    QString str0, str1, str2;
    //FIXME: put/Add -> set
    switch (ns->parseArgs(true)) {
    case 1:
        str1 = ns->getArg(0);
        ns->nd->effect["window"] =
                new NsEffect(ns->nd->evalNum(str1));
        break;

    case 2:
        str0 = ns->getArg(0);
        str1 = ns->getArg(1);
        ns->nd->effect["window"] =
                new NsEffect(ns->nd->evalNum(str0), ns->nd->evalNum(str1));
        break;

    case 3:
        str0 = ns->getArg(0);
        str1 = ns->getArg(1);
        str2 = ns->getArg(2);
        ns->nd->effect["window"] =
                new NsEffect(ns->nd->evalNum(str0), ns->nd->evalNum(str1), ns->nd->evalStr(str2));
        break;

    default:
        ns->error("windoweffect");
        break;
    }
}

