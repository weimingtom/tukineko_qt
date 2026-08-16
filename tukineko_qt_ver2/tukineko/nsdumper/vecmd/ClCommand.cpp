#include "ClCommand.h"
#include "NScripter.h"

ClCommand::ClCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

ClCommand::~ClCommand()
{
}

bool ClCommand::check(const QString &str)
{
    return str.startsWith("cl");
}

void ClCommand::execute()
{
    debug("[VECommand] cl");

    if (ns->parseArgs(true) < 2) {
        ns->error("cl");
    } else {
        if (ns->nd->evalStr(ns->getArg(0)) == "l") {
            ns->nd->shell[0] = NsShell(); //FIXME:nullptr;
        } else if (ns->nd->evalStr(ns->getArg(0)) == "c") {
            ns->nd->shell[1] = NsShell(); //FIXME:nullptr;
        } else if (ns->nd->evalStr(ns->getArg(0)) == "r") {
            ns->nd->shell[2] = NsShell(); //FIXME:nullptr;
        } else {
            ns->nd->shell[0] = NsShell(); //FIXME:nullptr;
            ns->nd->shell[1] = NsShell(); //FIXME:nullptr;
            ns->nd->shell[2] = NsShell(); //FIXME:nullptr;
        }
        ns->tn->paintB();
        ns->makeLineRest(2);
    }
}

