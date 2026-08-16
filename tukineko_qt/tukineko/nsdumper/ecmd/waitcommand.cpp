#include "waitcommand.h"

WaitCommand::WaitCommand() { m_cmdName = "wait"; }
WaitCommand::~WaitCommand() {}
bool WaitCommand::check(const QString& str) { return false; }
void WaitCommand::execute() {}
