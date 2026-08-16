#include "actionevent.h"

ActionEvent::ActionEvent()
    : m_command()
{
}

ActionEvent::ActionEvent(const QString& command)
    : m_command(command)
{
}

ActionEvent::~ActionEvent()
{
}
