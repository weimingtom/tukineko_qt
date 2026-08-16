#ifndef JAVA_LANG_THREAD_H
#define JAVA_LANG_THREAD_H

#include <QThread>
#include <QString>

namespace java {
namespace lang {

class Thread_ : public QThread {
    Q_OBJECT
public:
    Thread_();
    explicit Thread_(const QString& name);
    ~Thread_();

    void start();
    void run() override;
    void join();

private:
    QString m_name;
};

} // namespace lang
} // namespace java

#endif // JAVA_LANG_THREAD_H
