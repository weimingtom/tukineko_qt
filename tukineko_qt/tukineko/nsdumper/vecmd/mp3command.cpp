#include "mp3command.h"

Mp3Command::Mp3Command()
{
}

Mp3Command::~Mp3Command()
{
}

bool Mp3Command::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void Mp3Command::execute()
{
}
