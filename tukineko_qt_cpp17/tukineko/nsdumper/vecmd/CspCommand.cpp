#include "CspCommand.h"
#include "NScripter.h"

CspCommand::CspCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

CspCommand::~CspCommand()
{
}

bool CspCommand::check(const QString &str)
{
    return str.startsWith("csp");
}

void CspCommand::execute()
{
    debug("[VECommand] csp");

    if (ns->parseArgs(true) < 1) {
        ns->error("csp");
    } else {
        int i = ns->nd->evalNum(ns->getArg(0));
        if (i >= 0) {
            ns->nd->sprite[i].visible = false;
        } else {
            for (int i2 = 0; i2 < 50; i2++) {
                ns->nd->sprite[i2].visible = false;
            }
        }
        ns->makeLineRest(1);
    }
}
