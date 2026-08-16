#ifndef ACTIONLISTENER_H
#define ACTIONLISTENER_H

#include "actionevent.h"

class ActionListener
{
public:
    virtual ~ActionListener() {}

    virtual void actionPerformed(ActionEvent* event) = 0;
};

#endif // ACTIONLISTENER_H
