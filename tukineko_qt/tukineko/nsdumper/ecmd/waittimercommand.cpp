#include "waittimercommand.h"

WaittimerCommand::WaittimerCommand() { m_cmdName = "waittimer"; }
WaittimerCommand::~WaittimerCommand() {}
bool WaittimerCommand::check(const QString& str) { return false; }
void WaittimerCommand::execute() {}
