#include "btnwaitcommand.h"
#include "nscripter.h"
#include "nsbutton.h"
#include <QThread>

bool BtnwaitCommand::check(const QString &str)
{
    return checkCommand(str, "btnwait");
}

void BtnwaitCommand::execute()
{
    debug("[ECommand] btnwait");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    if (ns->parseArgs(true) < 1) {
        ns->error("btnwait");
    } else if (ns->nd->btn.isEmpty()) {
        ns->nd->click = false;
        do {
            QThread::msleep(100);
            if (ns->nd->click) {
                break;
            }
        } while (ns->storageState == 0);
    } else {
        ns->nd->btnVisible = true;
        ns->nd->click = false;
        int k = -1;
        NsButton localNsButton;
        while (ns->storageState == 0) {
            if (ns->nd->click == true) {
                ns->nd->click = false;
                k = -1;
                for (int j = 0; j < ns->nd->btn.size(); j++) {
                    localNsButton = ns->nd->btn[j];
                    if ((localNsButton.x > ns->nd->clickX) ||
                        (ns->nd->clickX >= localNsButton.x + localNsButton.width) ||
                        (localNsButton.y > ns->nd->clickY) ||
                        (ns->nd->clickY >= localNsButton.y + localNsButton.height)) {
                        continue;
                    }
                    k = j;
                    break;
                }
                if (ns->nd->btnSel != k) {
                    ns->nd->btnSel = k;
                } else {
                    if (ns->nd->btnSel >= 0) {
                        break;
                    }
                }
                ns->tn->paintB();
            }
            QThread::msleep(100);
        }
        if (!ns->getArg(0).startsWith("%")) {
            ns->error("btnwait");
        } else if (k >= 0) {
            localNsButton = ns->nd->btn[k];
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] = localNsButton.no;
        }
        ns->nd->btnVisible = false;
        ns->makeLineRest(1);
    }
}
