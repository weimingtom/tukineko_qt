#include "btncommand.h"
#include "nscripter.h"
#include "nsbutton.h"

bool BtnCommand::check(const QString &str)
{
    return checkCommand(str, "btn");
}

void BtnCommand::execute()
{
    debug("[ECommand] btn");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    if (ns->parseArgs(true) < 7) {
        ns->error("btn");
    } else {
        ns->nd->btn.append(NsButton(
            ns->nd->evalNum(ns->getArg(0)),
            ns->nd->evalNum(ns->getArg(1)),
            ns->nd->evalNum(ns->getArg(2)),
            ns->nd->evalNum(ns->getArg(3)),
            ns->nd->evalNum(ns->getArg(4)),
            ns->nd->evalNum(ns->getArg(5)),
            ns->nd->evalNum(ns->getArg(6))));
        ns->makeLineRest(7);
    }
}
