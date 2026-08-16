#ifndef NSACTIONLISTENER_H
#define NSACTIONLISTENER_H

#include <QObject>
#include "java/awt/event/actionlistener.h"
#include "java/awt/event/actionevent.h"

class NsWindow;
class NScripter;

class NsActionListener :
        //public QObject,
        public ActionListener
{
    //Q_OBJECT

public:
    explicit NsActionListener(NScripter* ns, NsWindow* window);// QObject* parent = nullptr);
    virtual ~NsActionListener();

    void actionPerformed(ActionEvent* event) override;

private:
    NScripter* m_ns;
    NsWindow* m_window;
};

#endif // NSACTIONLISTENER_H
