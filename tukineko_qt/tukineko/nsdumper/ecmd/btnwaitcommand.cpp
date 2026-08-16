#include "btnwaitcommand.h"

BtnwaitCommand::BtnwaitCommand() { m_cmdName = "btnwait"; }
BtnwaitCommand::~BtnwaitCommand() {}
bool BtnwaitCommand::check(const QString& str) { return false; }
void BtnwaitCommand::execute() {}
