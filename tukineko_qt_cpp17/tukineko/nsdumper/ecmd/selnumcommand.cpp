#include "selnumcommand.h"
#include "nscripter.h"
#include "nsselect.h"

bool SelnumCommand::check(const QString &str)
{
    return checkCommand(str, "selnum");
}

void SelnumCommand::execute()
{
    debug("[ECommand] selnum");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    if (ns->parseArgs(true) < 2) {
        ns->error("selnum");
    } else {
        if (!ns->getArg(0).startsWith("%")) {
            ns->error("selnum");
            return;
        }
        ns->nd->selnum = ns->nd->evalNum(ns->getArg(0).mid(1));
        int i = ns->getArgSize();
        int m = 0;
        while (true) {
            for (int j = (m == 0 ? 1 : 0); j < i; j++) {
                ns->nd->select.append(NsSelect(
                    ns->getArg(j),
                    QString::number(m++),
                    ns->nd->text->getY(),
                    ns->tn->putMess(ns->nd->text, ns->getArg(j), &ns->nd->textcolor, false, false),
                    false));
            }
            if (!ns->argCont) {
                break;
            }
            QString paramString = ns->readLine();
            i = ns->parseArgs(false);
        }
        if (!ns->nd->fadeFlag) {
            ns->tn->paintB();
        } else {
            ns->tn->paintF();
        }
        ns->selectWait();
    }
}
