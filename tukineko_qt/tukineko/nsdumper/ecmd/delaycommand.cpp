#include "delaycommand.h"

DelayCommand::DelayCommand() { m_cmdName = "delay"; }
DelayCommand::~DelayCommand() {}
bool DelayCommand::check(const QString& str) { return false; }
void DelayCommand::execute() {}
