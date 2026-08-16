#include "nsactionlistener.h"
#include "nswindow.h"
#include "nscripter.h"
#include <QDebug>

NsActionListener::NsActionListener(NScripter* ns, NsWindow* window)//, QObject* parent)
    : //QObject(parent),
      m_ns(ns)
    , m_window(window)
{
}

NsActionListener::~NsActionListener()
{
}

void NsActionListener::actionPerformed(ActionEvent* event)
{
    QString cmd = event->getActionCommand();
    qDebug() << "NsActionListener::actionPerformed:" << cmd;

    if (m_ns) {
        if (cmd.startsWith("SAVE")) {
            m_ns->save(cmd);
        } else if (cmd.startsWith("LOAD")) {
            m_ns->load(cmd);
        }
    }
}
