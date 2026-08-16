#include "captioncommand.h"
#include <iostream>

CaptionCommand::CaptionCommand()
{
    ns = NScripter::getInstance();
}

CaptionCommand::~CaptionCommand()
{
}

bool CaptionCommand::check(const QString& str)
{
    return checkCommand(str, "caption");
}

void CaptionCommand::execute()
{
    debug("[SFECommand] caption");

    std::cerr << "not implement: caption" << std::endl;
}
