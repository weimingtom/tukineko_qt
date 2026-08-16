#include "SkipCommand.h"
#include "NScripter.h"

SkipCommand::SkipCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool SkipCommand::check(const QString &str)
{
    return checkCommand(str, "skip");
}

void SkipCommand::execute()
{
    debug("[FECommand] skip");

    if (ns->parseArgs(true) < 1) {
        ns->error("skip");
    } else {
        int i = ns->nd->evalNum(ns->getArg(0));
        if (i < 0) {
            if ((i < -99) || (ns->nd->historyCount < -i)) {
                ns->error("skip:" + QString::number(i));
            } else {
                ns->backHistory(-i);
            }
        } else if (i > 1) {
            for (int j = 0; j < i - 1; j++) {
                ns->readLine();
            }
        }
        ns->makeLineRest(1);
    }
}
