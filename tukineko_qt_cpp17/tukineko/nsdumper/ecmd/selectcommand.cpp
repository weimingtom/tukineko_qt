#include "selectcommand.h"
#include "nscripter.h"
#include "nsselect.h"

bool SelectCommand::check(const QString &str)
{
    return checkCommand(str, "select");
}

void SelectCommand::execute()
{
    debug("[ECommand] select");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->nd->selSkipFlag = true;

    if (ns->parseArgs(true) % 2 != 0) {
        ns->error("select|selgosub");
    } else {
        int i = ns->getArgSize();
        while (true) {
            for (int j = 0; j < i; j += 2) {
                ns->nd->select.append(NsSelect(
                    ns->getArg(j),
                    ns->getArg(j + 1),
                    ns->nd->text->getY(),
                    ns->tn->putMess(ns->nd->text, ns->getArg(j), &ns->nd->textcolor, false, false),
                    false));
            }
            if (!ns->argCont)
                break;
            QString paramString = ns->readLine();
            i = ns->parseArgs(false);
        }
        if (!ns->nd->fadeFlag)
            ns->tn->paintB();
        else
            ns->tn->paintF();
        ns->selectWait();
    }
}
