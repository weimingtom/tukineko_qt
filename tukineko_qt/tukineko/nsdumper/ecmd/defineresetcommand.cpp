#include "defineresetcommand.h"

DefineresetCommand::DefineresetCommand() { m_cmdName = "definereset"; }
DefineresetCommand::~DefineresetCommand() {}
bool DefineresetCommand::check(const QString& str) { return false; }
void DefineresetCommand::execute() {}
