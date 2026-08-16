#include "nsthread.h"
#include <QDebug>

NsThread::NsThread(QObject* parent)
    : Thread_("NsThread", parent)
    , m_ns(nullptr)
{
}

NsThread::~NsThread()
{
}

void NsThread::runImpl()
{
    qDebug() << "NsThread::runImpl() - TODO: connect to NScripter";
}
