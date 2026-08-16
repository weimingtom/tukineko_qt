#include "clickposcommand.h"

ClickposCommand::ClickposCommand() { m_cmdName = "clickpos"; }
ClickposCommand::~ClickposCommand() {}
bool ClickposCommand::check(const QString& str) { return false; }
void ClickposCommand::execute() {}
