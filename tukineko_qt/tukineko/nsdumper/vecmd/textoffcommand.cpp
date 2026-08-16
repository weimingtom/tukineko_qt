#include "textoffcommand.h"

TextoffCommand::TextoffCommand()
{
}

TextoffCommand::~TextoffCommand()
{
}

bool TextoffCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void TextoffCommand::execute()
{
}
