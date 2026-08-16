#include "selectcommand.h"

SelectCommand::SelectCommand() { m_cmdName = "select"; }
SelectCommand::~SelectCommand() {}
bool SelectCommand::check(const QString& str) { return false; }
void SelectCommand::execute() {}
