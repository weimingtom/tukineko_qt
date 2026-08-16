#ifndef NSACTIONLISTENER_H
#define NSACTIONLISTENER_H

#include "java/awt/event/ActionListener.h"

namespace tukineko {

class NScripter;
class NsWindow;

class NsActionListener : public java::awt::event::ActionListener {
private:
    NScripter *ns;
    NsWindow *tn;

public:
    NsActionListener(NScripter *ns, NsWindow *tn);

    void actionPerformed(java::awt::event::ActionEvent *event_) override;
};

}

#endif // NSACTIONLISTENER_H
