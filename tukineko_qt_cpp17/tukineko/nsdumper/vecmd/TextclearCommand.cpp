#include "TextclearCommand.h"
#include "NScripter.h"

namespace tukineko {

TextclearCommand::TextclearCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

TextclearCommand::~TextclearCommand()
{
}

bool TextclearCommand::check(const QString &str)
{
    return str.startsWith("textclear");
}

void TextclearCommand::execute()
{
    debug("[VECommand] textclear");

    ns->error("textclear");
}

}
