#include "MonocroCommand.h"
#include <QDebug>

MonocroCommand::MonocroCommand()
{
}

MonocroCommand::~MonocroCommand()
{
}

bool MonocroCommand::check(const QString &str)
{
    return str.startsWith("monocro");
}

void MonocroCommand::execute()
{
    debug("[VECommand] monocro");

    qCritical() << "not implement: monocro";
}
