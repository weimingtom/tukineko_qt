#include "selnumcommand.h"

SelnumCommand::SelnumCommand() { m_cmdName = "selnum"; }
SelnumCommand::~SelnumCommand() {}
bool SelnumCommand::check(const QString& str) { return false; }
void SelnumCommand::execute() {}
