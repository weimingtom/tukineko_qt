#include "ecommand.h"

ECommand::ECommand() {}
ECommand::~ECommand() {}
bool ECommand::check(const QString& str) { Q_UNUSED(str); return false; }
void ECommand::execute() {}
