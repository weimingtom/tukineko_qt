#include "RndCommand.h"
#include "NScripter.h"
#include <QtGlobal>
#if QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
//qsrand and qrand in QtGlobal
#else
#include <QRandomGenerator>
#endif
#include <QDateTime>

RndCommand::RndCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool RndCommand::check(const QString &str)
{
    return checkCommand(str, "rnd");
}

void RndCommand::execute()
{
    debug("[FECommand] rnd");

    if (ns->parseArgs(true) < 2) {
        ns->error("rnd");
    } else {
        if (ns->getArg(0).startsWith("%")) {
            quint32 seed = static_cast<quint32>(QDateTime::currentMSecsSinceEpoch());
#if QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
            qsrand(seed);
            double randomVal = (qrand() % 100) / 100.0;
#else
            QRandomGenerator random(seed);
            double randomVal = random.bounded(100) / 100.0;
#endif
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] = static_cast<int>(randomVal * ns->nd->evalNum(ns->getArg(1)));
        } else {
            ns->error("rnd");
        }
        ns->makeLineRest(2);
    }
}
