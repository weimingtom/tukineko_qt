#ifndef IO_EXCEPTION_H
#define IO_EXCEPTION_H

#include <QString>
#include <exception>

class IOException : public std::exception
{
public:
    IOException() : std::exception() {}
    IOException(const QString& message) : std::exception(), m_message(message.toStdString().c_str()) {}
    IOException(const char* message) : std::exception(), m_message(message) {}
    
    const char* what() const noexcept override {
        return m_message.c_str();
    }

private:
    std::string m_message;
};

#endif // IO_EXCEPTION_H
