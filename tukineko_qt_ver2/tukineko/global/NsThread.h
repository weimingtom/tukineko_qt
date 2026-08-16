#ifndef NSTHREAD_H
#define NSTHREAD_H

#include <QThread>

namespace tukineko {

class NScripter;

class NsThread : public QThread {
    Q_OBJECT

private:
    NScripter *ns;

public:
    explicit NsThread(NScripter *ns, QObject *parent = nullptr);

protected:
    void run() override;
};

}

#endif // NSTHREAD_H
