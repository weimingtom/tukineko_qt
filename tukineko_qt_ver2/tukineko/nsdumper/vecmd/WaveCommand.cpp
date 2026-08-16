#include "WaveCommand.h"
#include <QDebug>

WaveCommand::WaveCommand()
{
}

WaveCommand::~WaveCommand()
{
}

bool WaveCommand::check(const QString &str)
{
    return str.startsWith("wave");
}

void WaveCommand::execute()
{
    debug("[VECommand] wave");

    qCritical() << "not implement: wave";
}
