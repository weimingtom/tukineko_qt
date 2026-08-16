#include "selgosubcommand.h"

SelgosubCommand::SelgosubCommand() { m_cmdName = "selgosub"; }
SelgosubCommand::~SelgosubCommand() {}
bool SelgosubCommand::check(const QString& str) { return false; }
void SelgosubCommand::execute() {}
