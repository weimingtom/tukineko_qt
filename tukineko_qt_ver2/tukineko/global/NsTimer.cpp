#include "NsTimer.h"

namespace tukineko {

NsTimer::NsTimer(QObject *parent)
    : QObject(parent), timer(0), clear_(false), loop(true)
{
    qTimer = new QTimer(this);
    qTimer->setInterval(1);
    connect(qTimer, &QTimer::timeout, this, &NsTimer::onTimeout);
    qTimer->start();
}

NsTimer::NsTimer(int paramInt, QObject *parent)
    : QObject(parent), timer(paramInt), clear_(false), loop(true)
{
    qTimer = new QTimer(this);
    qTimer->setInterval(1);
    connect(qTimer, &QTimer::timeout, this, &NsTimer::onTimeout);
    qTimer->start();
}

NsTimer::~NsTimer() {
    loop = false;
    if (qTimer) {
        qTimer->stop();
    }
}

void NsTimer::clear() {
    this->clear_ = true;
}

int NsTimer::read() const {
    return this->timer;
}

void NsTimer::exit() {
    this->loop = false;
    if (qTimer) {
        qTimer->stop();
    }
}

void NsTimer::onTimeout() {
    if (!loop) {
        return;
    }
    if (this->clear_) {
        this->clear_ = false;
        this->timer = -1;
    }
    this->timer += 1;
}

}
