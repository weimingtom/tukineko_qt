#include "NsThread.h"
#include "../parser/NScripter.h"

namespace tukineko {

NsThread::NsThread(NScripter *ns, QObject *parent)
    : QThread(parent), ns(ns)
{
}

void NsThread::run() {
    if (ns) {
        ns->run();
    }
}

}
