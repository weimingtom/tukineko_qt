#include "spicommand.h"
#include "nscripter.h"
#include <iostream>

SpiCommand::SpiCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool SpiCommand::check(const QString &str)
{
    return checkCommand(str, "spi");
}

void SpiCommand::execute()
{
    debug("[SFCommand] spi");

    std::cerr << "not implement: spi" << std::endl;
}
