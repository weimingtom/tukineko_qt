#ifndef NSTIMER_H
#define NSTIMER_H

#include <QObject>
#include <QTimer>

namespace tukineko {

class NsTimer : public QObject {
    Q_OBJECT

private:
    int timer;
    bool clear_;
    bool loop;
    QTimer *qTimer;

private slots:
    void onTimeout();

public:
    explicit NsTimer(QObject *parent = nullptr);
    explicit NsTimer(int paramInt, QObject *parent = nullptr);
    ~NsTimer();

    void clear();
    int read() const;
    void exit();
};

}

#endif // NSTIMER_H
