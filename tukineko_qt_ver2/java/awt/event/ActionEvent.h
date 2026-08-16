#ifndef JAVA_AWT_EVENT_ACTIONEVENT_H
#define JAVA_AWT_EVENT_ACTIONEVENT_H

#include <QObject>
#include <QString>

namespace java {
namespace awt {
namespace event {

class ActionEvent {
public:
    ActionEvent();

    QObject* getSource();
    QString getActionCommand();
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_ACTIONEVENT_H
