#include "NsActionListener.h"
#include "parser/NScripter.h"
#include "NsWindow.h"
#include "java/awt/Menu.h"
#include "java/awt/event/ActionEvent.h"

namespace tukineko {

NsActionListener::NsActionListener(NScripter *ns, NsWindow *tn)
    : ns(ns)
    , tn(tn)
{
}

void NsActionListener::actionPerformed(java::awt::event::ActionEvent *event_)
{
    QObject *localObject = event_->getSource();
    QString str = event_->getActionCommand();
    if (localObject == tn->menuSave) {
        ns->save(str);
        return;
    } else if (localObject == tn->menuLoad) {
        ns->load(str);
        return;
    } else {
        ns->menu3(str);
        return;
    }
}

}
