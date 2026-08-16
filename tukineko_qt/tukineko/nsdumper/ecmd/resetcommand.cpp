#include "resetcommand.h"

ResetCommand::ResetCommand() { m_cmdName = "reset"; }
ResetCommand::~ResetCommand() {}
bool ResetCommand::check(const QString& str) { return false; }
void ResetCommand::execute() {}
