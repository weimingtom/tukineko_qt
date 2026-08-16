#include "btndefcommand.h"

BtndefCommand::BtndefCommand() { m_cmdName = "btndef"; }
BtndefCommand::~BtndefCommand() {}
bool BtndefCommand::check(const QString& str) { return false; }
void BtndefCommand::execute() {}
