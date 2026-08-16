#include "textoncommand.h"

TextonCommand::TextonCommand()
{
}

TextonCommand::~TextonCommand()
{
}

bool TextonCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void TextonCommand::execute()
{
}
