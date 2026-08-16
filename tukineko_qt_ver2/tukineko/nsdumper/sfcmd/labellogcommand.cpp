#include "labellogcommand.h"
#include "nscripter.h"
#include <QFileInfo>

LabellogCommand::LabellogCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool LabellogCommand::check(const QString &str)
{
    return checkCommand(str, "labellog");
}

void LabellogCommand::execute()
{
    debug("[SFCommand] labellog");

    ns->setMsRest();
    ns->nd->labellog = true;
    QFileInfo localFile(ns->path + "NSCRLLOG.DAT");
    if (localFile.exists()) {
        tukineko::NScripter::loadLogData(ns->path + "NSCRLLOG.DAT", ns->nd->lchk);
    }
}
