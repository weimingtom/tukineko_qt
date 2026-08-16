#include "systemcallcommand.h"

SystemcallCommand::SystemcallCommand() { m_cmdName = "systemcall"; }
SystemcallCommand::~SystemcallCommand() {}
bool SystemcallCommand::check(const QString& str) { return false; }
void SystemcallCommand::execute() {}
