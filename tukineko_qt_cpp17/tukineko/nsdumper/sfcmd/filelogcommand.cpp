#include "filelogcommand.h"
#include "nscripter.h"
#include <QFileInfo>

FilelogCommand::FilelogCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool FilelogCommand::check(const QString &str)
{
    return checkCommand(str, "filelog");
}

void FilelogCommand::execute()
{
    debug("[SFCommand] filelog");

    ns->setMsRest();
    ns->nd->filelog = true;
    QFileInfo localFile(ns->path + "NSCRFLOG.DAT");
    if (localFile.exists()) {
        tukineko::NScripter::loadLogData(ns->path + "NSCRFLOG.DAT", ns->nd->fchk);
    }
}
