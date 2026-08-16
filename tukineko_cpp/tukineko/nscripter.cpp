#include "nscripter.h"
#include "nsdata.h"
#include "nsresource.h"
#include "../java_io/file_.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

NScripter::NScripter(NsData* data, NsResource* resource)
    : m_data(data)
    , m_resource(resource)
    , m_pc(0)
    , m_running(false)
{
}

NScripter::~NScripter()
{
}

void NScripter::init(const QStringList& argv)
{
    Q_UNUSED(argv);
    qDebug() << "NScripter initialized";
}

void NScripter::loadScript(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open script:" << filename;
        return;
    }
    
    QTextStream in(&file);
    m_scriptLines.clear();
    
    while (!in.atEnd()) {
        QString line = in.readLine();
        m_scriptLines.append(line);
    }
    
    file.close();
    parseLabels();
    qDebug() << "Loaded script:" << filename << "with" << m_scriptLines.size() << "lines";
}

void NScripter::execute()
{
    m_running = true;
    m_pc = 0;
    
    while (m_running && m_pc < m_scriptLines.size()) {
        QString line = m_scriptLines[m_pc];
        executeLine(line);
        m_pc++;
    }
    
    qDebug() << "Script execution finished";
}

void NScripter::parseLabels()
{
    m_labelMap.clear();
    
    for (int i = 0; i < m_scriptLines.size(); ++i) {
        QString line = m_scriptLines[i].trimmed();
        
        // Check for label (starts with * or :)
        if (line.startsWith('*') || line.startsWith(':')) {
            QString label = line.mid(1).trimmed();
            if (!label.isEmpty()) {
                m_labelMap[label] = i;
            }
        }
    }
    
    qDebug() << "Found" << m_labelMap.size() << "labels";
}

void NScripter::executeLine(const QString& line)
{
    QString trimmed = line.trimmed();
    if (trimmed.isEmpty() || trimmed.startsWith(';') || trimmed.startsWith('#')) {
        return;  // Skip empty lines, comments
    }
    
    // Parse command
    QString cmd;
    QStringList args;
    
    int spaceIdx = trimmed.indexOf(' ');
    if (spaceIdx > 0) {
        cmd = trimmed.left(spaceIdx).toLower();
        QString rest = trimmed.mid(spaceIdx + 1).trimmed();
        
        // Handle quoted strings
        if (rest.startsWith('"')) {
            int endQuote = rest.indexOf('"', 1);
            if (endQuote > 0) {
                args << rest.mid(1, endQuote - 1);
                rest = rest.mid(endQuote + 1).trimmed();
                if (!rest.isEmpty()) {
                    args << rest.split(' ', Qt::SkipEmptyParts);
                }
            }
        } else {
            args = rest.split(' ', Qt::SkipEmptyParts);
        }
    } else {
        cmd = trimmed.toLower();
    }
    
    processCommand(cmd, args);
}

void NScripter::processCommand(const QString& cmd, const QStringList& args)
{
    if (cmd == "goto") {
        if (!args.isEmpty()) {
            gotoLabel(args[0]);
        }
    }
    else if (cmd == "gosub") {
        if (!args.isEmpty()) {
            gosubLabel(args[0]);
        }
    }
    else if (cmd == "return") {
        return_();
    }
    else if (cmd == "end") {
        m_running = false;
    }
    else if (cmd == "mov" || cmd == "=") {
        if (args.size() >= 2) {
            bool ok;
            int value = args[1].toInt(&ok);
            if (ok) {
                setVariable(args[0], value);
            }
        }
    }
    else if (cmd == "add") {
        if (args.size() >= 2) {
            bool ok;
            int value = args[1].toInt(&ok);
            if (ok) {
                int current = getVariable(args[0]);
                setVariable(args[0], current + value);
            }
        }
    }
    else if (cmd == "sub") {
        if (args.size() >= 2) {
            bool ok;
            int value = args[1].toInt(&ok);
            if (ok) {
                int current = getVariable(args[0]);
                setVariable(args[0], current - value);
            }
        }
    }
    else if (cmd == "if") {
        // Simple if handling
        // if var > 0 goto label
        // (simplified implementation)
    }
    else if (cmd == "bg" || cmd == "lsp") {
        // Image loading commands
        // These would call into NsWindow
    }
    else if (cmd == "click" || cmd == "wait") {
        // Wait/click to continue
    }
    else if (cmd == "mes") {
        // Message display
    }
    else {
        qDebug() << "Unknown command:" << cmd;
    }
}

void NScripter::gotoLabel(const QString& label)
{
    if (m_labelMap.contains(label)) {
        m_pc = m_labelMap[label];
    } else {
        qDebug() << "Label not found:" << label;
    }
}

void NScripter::gosubLabel(const QString& label)
{
    if (m_labelMap.contains(label)) {
        m_gosubStack.append(QStringList() << QString::number(m_pc));
        m_pc = m_labelMap[label];
    } else {
        qDebug() << "Label not found for gosub:" << label;
    }
}

void NScripter::return_()
{
    if (!m_gosubStack.isEmpty()) {
        QStringList saved = m_gosubStack.takeLast();
        if (!saved.isEmpty()) {
            bool ok;
            m_pc = saved[0].toInt(&ok);
            if (!ok) m_pc++;
        }
    }
}

int NScripter::getVariable(const QString& name)
{
    return m_data->getVariable(name);
}

void NScripter::setVariable(const QString& name, int value)
{
    m_data->setVariable(name, value);
}

void NScripter::addVariable(const QString& name, int value)
{
    int current = getVariable(name);
    setVariable(name, current + value);
}

void NScripter::setCurrentScript(const QString& script)
{
    loadScript(script);
}

int NScripter::getScriptPosition()
{
    return m_pc;
}

void NScripter::setScriptPosition(int pos)
{
    m_pc = pos;
}

bool NScripter::hasLabel(const QString& label)
{
    return m_labelMap.contains(label);
}
