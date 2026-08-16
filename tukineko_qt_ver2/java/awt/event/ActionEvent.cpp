#include "ActionEvent.h"

namespace java {
namespace awt {
namespace event {

ActionEvent::ActionEvent()
{
}

QObject* ActionEvent::getSource()
{
    return nullptr;
}

QString ActionEvent::getActionCommand()
{
    return QString();
}

} // namespace event
} // namespace awt
} // namespace java
