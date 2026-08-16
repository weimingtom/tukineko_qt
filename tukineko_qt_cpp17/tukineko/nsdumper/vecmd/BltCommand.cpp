#include "BltCommand.h"
#include "NScripter.h"

BltCommand::BltCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

BltCommand::~BltCommand()
{
}

bool BltCommand::check(const QString &str)
{
    return checkCommand(str, "blt");
}

void BltCommand::execute()
{
    debug("[VECommand] blt");

    if (ns->parseArgs(true) < 8) {
        ns->error("bly");
    } else {
        int j = ns->nd->evalNum(ns->getArg(0));
        int k = ns->nd->evalNum(ns->getArg(1));
        int m = ns->nd->evalNum(ns->getArg(2));
        int n = ns->nd->evalNum(ns->getArg(3));
        int i1 = ns->nd->evalNum(ns->getArg(4));
        int i2 = ns->nd->evalNum(ns->getArg(5));
        ns->nd->evalNum(ns->getArg(6));
        ns->nd->evalNum(ns->getArg(7));
        ns->makeLineRest(8);

        ns->tn->blt(j, k, m, n, i1, i2);
        ns->tn->paintB();
    }
}

