#include "gettimercommand.h"

GettimerCommand::GettimerCommand() { m_cmdName = "gettimer"; }
GettimerCommand::~GettimerCommand() {}
bool GettimerCommand::check(const QString& str) { return false; }
void GettimerCommand::execute() {}
