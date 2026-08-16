#include "Mp3Command.h"
#include "NScripter.h"

Mp3Command::Mp3Command()
    : ns(tukineko::NScripter::getInstance())
{
}

Mp3Command::~Mp3Command()
{
}

bool Mp3Command::check(const QString &str)
{
    return str.startsWith("mp3");
}

void Mp3Command::execute()
{
    debug("[VECommand] mp3");

    ns->error("mp3");
}
