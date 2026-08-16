#include "thread.h"
#include <QDebug>

Thread_::Thread_(const QString& name, QObject* parent)
    : QThread(parent)
    , m_name(name)
{
}

Thread_::~Thread_()
{
}

void Thread_::start()
{
    QThread::start();
}

void Thread_::run()
{
    runImpl();
}

void Thread_::join()
{
    wait();
}
