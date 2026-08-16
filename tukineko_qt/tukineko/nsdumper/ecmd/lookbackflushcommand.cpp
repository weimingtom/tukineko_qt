#include "lookbackflushcommand.h"

LookbackflushCommand::LookbackflushCommand() { m_cmdName = "lookbackflush"; }
LookbackflushCommand::~LookbackflushCommand() {}
bool LookbackflushCommand::check(const QString& str) { return false; }
void LookbackflushCommand::execute() {}
