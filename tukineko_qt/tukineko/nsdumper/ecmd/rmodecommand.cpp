#include "rmodecommand.h"

RmodeCommand::RmodeCommand() { m_cmdName = "rmode"; }
RmodeCommand::~RmodeCommand() {}
bool RmodeCommand::check(const QString& str) { return false; }
void RmodeCommand::execute() {}
