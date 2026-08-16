#include "TextonCommand.h"
#include "NScripter.h"

TextonCommand::TextonCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

TextonCommand::~TextonCommand()
{
}

bool TextonCommand::check(const QString &str)
{
    return str.startsWith("texton");
}

void TextonCommand::execute()
{
    debug("[VECommand] texton");

    ns->error("texton");
}
