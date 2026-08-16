#include "QuakeyCommand.h"
#include "NScripter.h"
#include <QThread>

namespace tukineko {

QuakeyCommand::QuakeyCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

QuakeyCommand::~QuakeyCommand()
{
}

bool QuakeyCommand::check(const QString &str)
{
    return str.startsWith("quakey");
}

void QuakeyCommand::execute()
{
    debug("[VECommand] quakey");

    if (ns->parseArgs(true) < 2) {
        ns->error("quakey");
    } else {
        for (int i = 0; i < ns->nd->evalNum(ns->getArg(0)); i++) {
            ns->nd->quakey += 1;
            ns->tn->paintB();
            QThread::msleep(ns->nd->evalNum(ns->getArg(1)));
        }
        ns->nd->quakey = 0;
        ns->tn->paintB();
        ns->makeLineRest(2);
    }
}

}
