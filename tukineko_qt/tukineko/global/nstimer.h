#ifndef NSTIMER_H
#define NSTIMER_H

#include "java/lang/thread.h"

class NsTimer : public Thread_
{
    Q_OBJECT

public:
    NsTimer();
    NsTimer(int initialValue);
    virtual ~NsTimer();

    void clear();
    int read();
    void exit();

protected:
    void runImpl() override;

private:
    int m_timer;
    bool m_clear;
    bool m_loop;
};

#endif // NSTIMER_H
