#include "notifcommand.h"

NotifCommand::NotifCommand()
{

}

NotifCommand::~NotifCommand()
{

}

bool NotifCommand::check(const QString& str)
{
    return str.startsWith("notif ");
}

void NotifCommand::execute()
{

}
