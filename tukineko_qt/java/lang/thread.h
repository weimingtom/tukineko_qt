#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QString>

class Thread_ : public QThread
{
    Q_OBJECT

public:
    explicit Thread_(const QString& name = QString(), QObject* parent = nullptr);
    virtual ~Thread_();

    void start();
    void run() override;
    void join();

    virtual void runImpl() = 0;

signals:
    void finished();

private:
    QString m_name;
};

#endif // THREAD_H
