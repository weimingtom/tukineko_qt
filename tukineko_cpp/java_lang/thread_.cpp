#include "thread_.h"
#include <QMutexLocker>
#include <QThread>

Thread_::Thread_()
    : m_runnable(nullptr)
    , m_interrupted(false)
    , m_started(false)
{
}

Thread_::Thread_(Runnable* runnable)
    : m_runnable(runnable)
    , m_interrupted(false)
    , m_started(false)
{
}

Thread_::~Thread_()
{
}

void Thread_::start()
{
    QMutexLocker locker(&m_mutex);
    m_started = true;
    QThread::start();
}

void Thread_::start(int priority)
{
    QMutexLocker locker(&m_mutex);
    m_started = true;
    QThread::start(static_cast<QThread::Priority>(priority));
}

void Thread_::run()
{
    if (m_runnable) {
        m_runnable->run();
    }
}

void Thread_::sleep(long secs)
{
    QThread::sleep(secs);
}

void Thread_::sleep(long secs, long millis)
{
    QThread::msleep(secs * 1000 + millis);
}

void Thread_::yield()
{
    QThread::yieldCurrentThread();
}

bool Thread_::isAlive()
{
    return m_started && !isFinished();
}

void Thread_::join()
{
    QThread::wait();
}

void Thread_::interrupt()
{
    QMutexLocker locker(&m_mutex);
    m_interrupted = true;
}

bool Thread_::isInterrupted()
{
    QMutexLocker locker(&m_mutex);
    return m_interrupted;
}

Thread_* Thread_::currentThread()
{
    // Create a wrapper for the current QThread
    return nullptr; // This would need special handling in actual implementation
}

void Thread_::sleepStatic(long secs)
{
    QThread::sleep(secs);
}

void Thread_::sleepStatic(long secs, long millis)
{
    QThread::msleep(secs * 1000 + millis);
}
