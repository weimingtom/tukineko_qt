#include "TextoffCommand.h"
#include "NScripter.h"

namespace tukineko {

TextoffCommand::TextoffCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

TextoffCommand::~TextoffCommand()
{
}

bool TextoffCommand::check(const QString &str)
{
    return str.startsWith("textoff");
}

void TextoffCommand::execute()
{
    debug("[VECommand] textoff");

    ns->error("textoff");
}

}
