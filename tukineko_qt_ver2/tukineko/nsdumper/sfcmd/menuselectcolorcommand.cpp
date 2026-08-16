#include "menuselectcolorcommand.h"
#include "nscripter.h"

MenuselectcolorCommand::MenuselectcolorCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool MenuselectcolorCommand::check(const QString &str)
{
    return checkCommand(str, "menuselectcolor");
}

void MenuselectcolorCommand::execute()
{
    debug("[SFCommand] menuselectcolor");

    if (ns->parseArgs(true) < 3) {
        ns->error("menuselectcolor");
    } else {
        ns->nd->menuselectcolorOn = ns->nd->evalColor(ns->nd->evalStr(ns->getArg(0)));
        ns->nd->menuselectcolorOut = ns->nd->evalColor(ns->nd->evalStr(ns->getArg(1)));
        ns->nd->menuselectcolorNosave = ns->nd->evalColor(ns->nd->evalStr(ns->getArg(2)));
        ns->makeLineRest(3);
    }
}
