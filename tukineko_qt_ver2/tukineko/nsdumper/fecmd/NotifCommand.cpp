#include "NotifCommand.h"
#include "NScripter.h"

NotifCommand::NotifCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool NotifCommand::check(const QString &str)
{
    return checkCommand(str, "notif");
}

void NotifCommand::execute()
{
    debug("[FECommand] notif");

    bool bl = true;
    int j = 1;
    int k = 0;
    int i1 = 0;
    int m = 0;
    ns->parseArgs(true);
    while (true) {
        QString str = ns->getArg(k);
        if (str == "fchk") {
            k++;
            bl = ns->nd->fchk.contains(ns->nd->evalStr(ns->getArg(k)).toUpper());
        } else if (str == "lchk") {
            k++;
            bl = ns->nd->lchk.contains(ns->getArg(k).mid(1).toUpper());
        } else {
            int n;
            if ((n = str.indexOf(">=")) >= 0) {
                i1 = n + 2;
                m = 0;
            } else if ((n = str.indexOf("<=")) >= 0) {
                i1 = n + 2;
                m = 1;
            } else if ((n = str.indexOf("<>")) >= 0) {
                i1 = n + 2;
                m = 2;
            } else if ((n = str.indexOf("!=")) >= 0) {
                i1 = n + 2;
                m = 2;
            } else if ((n = str.indexOf("==")) >= 0) {
                i1 = n + 2;
                m = 3;
            } else if ((n = str.indexOf("=")) >= 0) {
                i1 = n + 1;
                m = 3;
            } else if ((n = str.indexOf(">")) >= 0) {
                i1 = n + 1;
                m = 4;
            } else if ((n = str.indexOf("<")) >= 0) {
                i1 = n + 1;
                m = 5;
            }
            if (n < 0) {
                ns->error("if: " + QString::number(n));
                return;
            }
            int i2 = ns->nd->evalNum(str.mid(0, n));
            int i3 = ns->nd->evalNum(str.mid(i1));
            switch (m) {
            case 0:
                bl = i2 >= i3;
                break;
            case 1:
                bl = i2 <= i3;
                break;
            case 2:
                bl = i2 != i3;
                break;
            case 3:
                bl = i2 == i3;
                break;
            case 4:
                bl = i2 > i3;
                break;
            case 5:
                bl = i2 < i3;
                break;
            }
        }
        if (bl)
            j = 0;
        if ((ns->getArg(k + 1) != "&") && (ns->getArg(k + 1) != "&&")) {
            break;
        }
        k += 2;
    }
    if (j == 1) {
        ns->makeLineRest(k + 1);
    } else {
        ns->lineRest = QString();
    }
}
