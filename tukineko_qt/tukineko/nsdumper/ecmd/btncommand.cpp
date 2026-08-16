#include "btncommand.h"

BtnCommand::BtnCommand() { m_cmdName = "btn"; }
BtnCommand::~BtnCommand() {}
bool BtnCommand::check(const QString& str) { return false; }
void BtnCommand::execute() {}
