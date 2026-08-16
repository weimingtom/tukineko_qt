#ifndef THREAD__H
#define THREAD__H

#include <QThread>
#include <QMutex>

class Runnable
{
public:
    virtual ~Runnable() {}
    virtual void run() = 0;
};

class Thread_ : public QThread
{
public:
    Thread_();
    Thread_(Runnable* runnable);
    virtual ~Thread_();
    
    void start();
    void start(int priority);
    void run() override;
    void sleep(long secs);
    void sleep(long secs, long millis);
    void yield();
    bool isAlive();
    void join();
    void interrupt();
    bool isInterrupted();
    
    static Thread_* currentThread();
    static void sleepStatic(long secs);
    static void sleepStatic(long secs, long millis);

private:
    Runnable* m_runnable;
    bool m_interrupted;
    bool m_started;
    QMutex m_mutex;
};

#endif // THREAD__H
