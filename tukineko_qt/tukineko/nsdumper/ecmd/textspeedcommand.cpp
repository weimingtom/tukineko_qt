#include "textspeedcommand.h"

TextspeedCommand::TextspeedCommand() { m_cmdName = "textspeed"; }
TextspeedCommand::~TextspeedCommand() {}
bool TextspeedCommand::check(const QString& str) { return false; }
void TextspeedCommand::execute() {}
