#include "LdCommand.h"
#include "NScripter.h"

LdCommand::LdCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

LdCommand::~LdCommand()
{
}

bool LdCommand::check(const QString &str)
{
    return checkCommand(str, "ld");
}

void LdCommand::execute()
{
    debug("[VECommand] ld");

    if (ns->parseArgs(true) < 3) {
        ns->error("ld");
    } else {
        int j;
        if (ns->nd->evalStr(ns->getArg(0)) == "l")
            j = 0;
        else if (ns->nd->evalStr(ns->getArg(0)) == "r")
            j = 2;
        else {
            j = 1;
        }
        QString imageName = ns->nd->evalStr(ns->getArg(1));
        ns->nd->shell[j] = new NsShell(imageName,
                ns->nd->evalNum(ns->getArg(2)),
                ns->tn->getImageWidth(imageName),
                ns->tn->getImageHeight(imageName));
        ns->tn->paintB();
        ns->makeLineRest(3);
    }
}

