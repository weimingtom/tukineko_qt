#ifndef NSTHREAD_H
#define NSTHREAD_H

#include "java/lang/thread.h"

class NsThread : public Thread_
{
    Q_OBJECT

public:
    NsThread(QObject* parent = nullptr);
    virtual ~NsThread();

protected:
    void runImpl() override;

private:
    class NScripter* m_ns;
};

#endif // NSTHREAD_H
