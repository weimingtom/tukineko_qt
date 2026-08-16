#include "QuakexCommand.h"
#include "NScripter.h"
#include <QThread>

namespace tukineko {

QuakexCommand::QuakexCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

QuakexCommand::~QuakexCommand()
{
}

bool QuakexCommand::check(const QString &str)
{
    return str.startsWith("quakex");
}

void QuakexCommand::execute()
{
    debug("[VECommand] quakex");

    if (ns->parseArgs(true) < 2) {
        ns->error("quakex");
    } else {
        for (int i = 0; i < ns->nd->evalNum(ns->getArg(0)); i++) {
            ns->nd->quakex += 1;
            ns->tn->paintB();
            QThread::msleep(ns->nd->evalNum(ns->getArg(1)));
        }
        ns->nd->quakex = 0;
        ns->tn->paintB();
        ns->makeLineRest(2);
    }
}

}
