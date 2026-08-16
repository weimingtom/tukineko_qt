#include "clickcommand.h"

ClickCommand::ClickCommand() { m_cmdName = "click"; }
ClickCommand::~ClickCommand() {}
bool ClickCommand::check(const QString& str) { return false; }
void ClickCommand::execute() {}
