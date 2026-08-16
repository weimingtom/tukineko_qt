#include "rmenucommand.h"
#include "nscripter.h"

RmenuCommand::RmenuCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool RmenuCommand::check(const QString &str)
{
    return checkCommand(str, "rmenu");
}

void RmenuCommand::execute()
{
    debug("[SFCommand] rmenu");

    int j;
    if ((j = ns->parseArgs(true)) % 2 != 0) {
        ns->error("rmenu");
    } else {
        for (int i = 0; i < j; i += 2) {
            if ("skip" == ns->nd->evalStr(ns->getArg(i + 1))) {
                ns->nd->rmenu[0] = ns->nd->evalStr(ns->getArg(i));
                if ((ns->nd->rotate)
                        && (ns->nd->rmenu[0].length() >= 5)) {
                    ns->nd->rmenu[0] = ns->nd->rmenu[0].left(5);
                }
                ns->tn->popupMenuAdd(ns->nd->rmenu[0]);
            } else if ("reset" == ns->nd->evalStr(ns->getArg(i + 1))) {
                ns->nd->rmenu[1] = ns->nd->evalStr(ns->getArg(i));
                if ((ns->nd->rotate)
                        && (ns->nd->rmenu[1].length() >= 5)) {
                    ns->nd->rmenu[1] = ns->nd->rmenu[1].left(5);
                }
                ns->tn->popupMenuAdd(ns->nd->rmenu[1]);
            } else if ("save" == ns->nd->evalStr(ns->getArg(i + 1))) {
                ns->nd->rmenu[2] = ns->nd->evalStr(ns->getArg(i));
                if ((ns->nd->rotate)
                        && (ns->nd->rmenu[2].length() >= 5)) {
                    ns->nd->rmenu[2] = ns->nd->rmenu[2].left(5);
                }
                ns->tn->createMenuSave(ns->nd->rmenu[2]);
            } else if ("load" == ns->nd->evalStr(ns->getArg(i + 1))) {
                ns->nd->rmenu[3] = ns->nd->evalStr(ns->getArg(i));
                if ((ns->nd->rotate)
                        && (ns->nd->rmenu[3].length() >= 5)) {
                    ns->nd->rmenu[3] = ns->nd->rmenu[3].left(5);
                }
                ns->tn->createMenuLoad(ns->nd->rmenu[3]);
            } else if ("lookback"
                    == ns->nd->evalStr(ns->getArg(i + 1))) {
                ns->nd->rmenu[4] = ns->nd->evalStr(ns->getArg(i));
                if ((ns->nd->rotate)
                        && (ns->nd->rmenu[4].length() >= 5)) {
                    ns->nd->rmenu[4] = ns->nd->rmenu[4].left(5);
                }
                ns->tn->popupMenuAdd(ns->nd->rmenu[4]);
            } else if ("windowerase" == ns->nd->evalStr(ns->getArg(i + 1))) {
                ns->nd->rmenu[5] = ns->nd->evalStr(ns->getArg(i));
                if ((ns->nd->rotate)
                        && (ns->nd->rmenu[5].length() >= 5))
                    ns->nd->rmenu[5] = ns->nd->rmenu[5].left(5);
                ns->tn->popupMenuAdd(ns->nd->rmenu[5]);
            } else {
                ns->error("rmenu: " + ns->nd->evalStr(ns->getArg(i)));
            }
        }
    }
}
