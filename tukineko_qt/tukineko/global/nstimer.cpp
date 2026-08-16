#include "nstimer.h"
#include <QDebug>
#include <QThread>

NsTimer::NsTimer()
    : Thread_("NsTimer")
    , m_timer(0)
    , m_clear(false)
    , m_loop(true)
{
    start();
}

NsTimer::NsTimer(int initialValue)
    : Thread_("NsTimer")
    , m_timer(initialValue)
    , m_clear(false)
    , m_loop(true)
{
    start();
}

NsTimer::~NsTimer()
{
}

void NsTimer::clear()
{
    m_clear = true;
}

int NsTimer::read()
{
    return m_timer;
}

void NsTimer::exit()
{
    m_loop = false;
    join();
}

void NsTimer::runImpl()
{
    while (m_loop) {
        if (m_clear) {
            m_clear = false;
            m_timer = -1;
        }
        m_timer += 1;
        QThread::msleep(1);
    }
}
