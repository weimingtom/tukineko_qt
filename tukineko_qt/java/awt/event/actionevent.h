#ifndef ACTIONEVENT_H
#define ACTIONEVENT_H

#include <QString>

class ActionEvent
{
public:
    ActionEvent();
    ActionEvent(const QString& command);
    virtual ~ActionEvent();

    QString getActionCommand() const { return m_command; }

private:
    QString m_command;
};

#endif // ACTIONEVENT_H
