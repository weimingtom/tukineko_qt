#include "textclearcommand.h"

TextclearCommand::TextclearCommand()
{
}

TextclearCommand::~TextclearCommand()
{
}

bool TextclearCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void TextclearCommand::execute()
{
}
