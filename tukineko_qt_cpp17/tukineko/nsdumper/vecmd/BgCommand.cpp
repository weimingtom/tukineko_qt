#include "BgCommand.h"
#include "NScripter.h"

BgCommand::BgCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

BgCommand::~BgCommand()
{
}

bool BgCommand::check(const QString &str)
{
    return checkCommand(str, "bg");
}

void BgCommand::execute()
{
    debug("[VECommand] bg");

    if (ns == nullptr) {
        debug("[VECommand] bg ns == null");
        return;
    }

    if (ns->parseArgs(true) < 2) {
        ns->error("bg");
    } else {
        if (ns->getArg(0) == "black") {
            ns->nd->bgColor = NsColor::black;
            ns->nd->bgImage = nullptr;
        } else if (ns->getArg(0) == "white") {
            ns->nd->bgColor = NsColor::white;
            ns->nd->bgImage = nullptr;
        } else if (ns->getArg(0).startsWith("#")) {
            ns->nd->bgColor = ns->nd->evalColor(ns->getArg(0));
            ns->nd->bgImage = nullptr;
        } else {
            ns->nd->bgColor = nullptr;
            ns->nd->bgImage = ns->nd->evalStr(ns->getArg(0));
        }
        ns->nd->bgEffect = ns->nd->evalNum(ns->getArg(1));
        for (int i = 0; i < 3; i++) {
            ns->nd->shell[i] = nullptr;
        }
        ns->tn->paintB();
        ns->makeLineRest(2);
    }
}
