#include "resettimercommand.h"

ResettimerCommand::ResettimerCommand() { m_cmdName = "resettimer"; }
ResettimerCommand::~ResettimerCommand() {}
bool ResettimerCommand::check(const QString& str) { return false; }
void ResettimerCommand::execute() {}
