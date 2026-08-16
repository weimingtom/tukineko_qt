#include "inputstrcommand.h"

InputstrCommand::InputstrCommand() { m_cmdName = "inputstr"; }
InputstrCommand::~InputstrCommand() {}
bool InputstrCommand::check(const QString& str) { return false; }
void InputstrCommand::execute() {}
