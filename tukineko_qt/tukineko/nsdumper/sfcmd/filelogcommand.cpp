#include "filelogcommand.h"

FilelogCommand::FilelogCommand()
{
}

FilelogCommand::~FilelogCommand()
{
}

bool FilelogCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void FilelogCommand::execute()
{
}
