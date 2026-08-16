#include "trapcommand.h"

TrapCommand::TrapCommand() { m_cmdName = "trap"; }
TrapCommand::~TrapCommand() {}
bool TrapCommand::check(const QString& str) { return false; }
void TrapCommand::execute() {}
