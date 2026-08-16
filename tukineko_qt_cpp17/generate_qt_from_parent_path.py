#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Generate Qt C++ .h and .cpp files from C# command classes
"""

import os
import re
import glob

# Base class templates
BASE_H_TEMPLATE = """#ifndef {guard}_H
#define {guard}_H

#include <QString>
#include <QDebug>

class {base_class}
{{
public:
    {base_class}();
    virtual ~{base_class}();

    virtual bool check(const QString &str);
    virtual void execute();

protected:
    bool checkCommand(const QString &paramString1, const QString &paramString2);
    void debug(const QString &str);
}};

#endif // {guard}_H
"""

BASE_CPP_TEMPLATE = """#include "{header_file}"

{base_class}::{base_class}()
{{
}}

{base_class}::~{base_class}()
{{
}}

bool {base_class}::check(const QString &str)
{{
    Q_UNUSED(str)
    return false;
}}

void {base_class}::execute()
{{
}}

bool {base_class}::checkCommand(const QString &paramString1, const QString &paramString2)
{{
    if (paramString1 == paramString2) {{
        return true;
    }}
    if (paramString1.length() > paramString2.length() &&
        paramString1.startsWith(paramString2) &&
        (paramString1[paramString2.length()] == ' ' || paramString1[paramString2.length()] == '\\t')) {{
        return true;
    }}
    return false;
}}

void {base_class}::debug(const QString &str)
{{
    qDebug() << str;
}}
"""

# Derived class templates
DERIVED_H_TEMPLATE = """#ifndef {guard}_H
#define {guard}_H

#include "{base_header}"
#include "../parser/NSParser.h"

class {class_name} : public {base_class}
{{
public:
    {class_name}();
    ~{class_name}() override;

    bool check(const QString &str) override;
    void execute() override;

private:
    NScripter *ns;
}};

#endif // {guard}_H
"""

DERIVED_CPP_TEMPLATE = """#include "{header_file}"

{class_name}::{class_name}()
    : ns(NScripter::getInstance())
{{
}}

{class_name}::~{class_name}()
{{
}}

bool {class_name}::check(const QString &str)
{{
    return checkCommand(str, "{command_name}");
}}

void {class_name}::execute()
{{
    debug("[{base_class}] {command_name}");
    {body}
}}
"""

# Special cases for check methods that use str.StartsWith instead of checkCommand
STARTSWITH_CHECK_TEMPLATE = """bool {class_name}::check(const QString &str)
{{
    return str.startsWith("{command_name}");
}}
"""

def to_guard(name):
    return re.sub(r'(?<!^)(?=[A-Z])', '_', name).upper()

def generate_base_class(base_name, output_dir):
    guard = to_guard(base_name)
    h_content = BASE_H_TEMPLATE.format(
        guard=guard,
        base_class=base_name
    )
    cpp_content = BASE_CPP_TEMPLATE.format(
        header_file=f"{base_name.lower()}.h",
        base_class=base_name
    )
    
    h_path = os.path.join(output_dir, f"{base_name.lower()}.h")
    cpp_path = os.path.join(output_dir, f"{base_name.lower()}.cpp")
    
    with open(h_path, 'w', encoding='utf-8') as f:
        f.write(h_content)
    with open(cpp_path, 'w', encoding='utf-8') as f:
        f.write(cpp_content)
    
    print(f"Generated: {h_path}")
    print(f"Generated: {cpp_path}")

def parse_cs_file(cs_path):
    """Parse a C# command file and extract key information"""
    with open(cs_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Extract class name and base class
    class_match = re.search(r'public\s+class\s+(\w+)\s*:\s*(\w+)', content)
    if not class_match:
        return None
    
    class_name = class_match.group(1)
    base_class = class_match.group(2)
    
    # Extract command name from check method
    check_match = re.search(r'return\s+(?:checkCommand\(str,\s*"([^"]+)"\)|str\.StartsWith\("([^"]+)"\))', content)
    command_name = check_match.group(1) if check_match and check_match.group(1) else (check_match.group(2) if check_match else class_name.replace('Command', '').lower())
    
    # Check if it uses StartsWith or checkCommand
    uses_startswith = 'str.StartsWith' in content
    
    # Extract execute body
    execute_match = re.search(r'public\s+override\s+void\s+execute\(\)\s*\{(.*?)\n\t\}\n\}', content, re.DOTALL)
    if not execute_match:
        execute_match = re.search(r'public\s+override\s+void\s+execute\(\)\s*\{(.*?)\n\t\}\n', content, re.DOTALL)
    
    body = execute_match.group(1).strip() if execute_match else ""
    
    # Check if has NScripter instance
    has_ns = 'NScripter ns = NScripter.getInstance();' in content or 'NScripter ns=NScripter.getInstance();' in content
    
    return {
        'class_name': class_name,
        'base_class': base_class,
        'command_name': command_name,
        'uses_startswith': uses_startswith,
        'body': body,
        'has_ns': has_ns,
        'content': content
    }

def convert_body(body, class_info):
    """Convert C# execute body to C++"""
    lines = body.split('\n')
    result = []
    
    for line in lines:
        original = line
        # Skip debug line (we keep it but convert syntax)
        if 'debug(' in line and '[ECommand]' in line or '[FCommand]' in line or '[FECommand]' in line or '[SECommand]' in line or '[SFCommand]' in line or '[SFECommand]' in line or '[VECommand]' in line or '[VFECommand]' in line:
            line = line.replace('debug("', 'debug(QStringLiteral("').replace('");', '"));')
        
        # Convert String to QString
        line = line.replace('String ', 'QString ')
        line = line.replace('(String ', '(QString ')
        
        # Convert bool
        line = line.replace('bool ', 'bool ')
        
        # Convert int
        line = line.replace('int ', 'int ')
        
        # Convert Console.Error.WriteLine to qDebug
        if 'Console.Error.WriteLine' in line:
            msg = re.search(r'Console\.Error\.WriteLine\((.*?)\);', line)
            if msg:
                line = f'    qDebug() << {msg.group(1)};'
        
        # Convert Console.WriteLine to qDebug
        if 'Console.WriteLine' in line:
            msg = re.search(r'Console\.WriteLine\((.*?)\);', line)
            if msg:
                line = f'    qDebug() << {msg.group(1)};'
        
        # Convert Thread.Sleep to QThread::msleep
        line = re.sub(r'Thread\.Sleep\((.*?)\)', r'QThread::msleep(\1)', line)
        
        # Convert try-catch to try-catch (C++ style)
        if 'try {' in line:
            line = line.replace('try {', 'try {')
        if 'catch (Exception)' in line or 'catch (IOException)' in line:
            line = '    catch (...) {'
        if '} catch' in line:
            line = '} catch (...) {'
        
        # Convert .Equals to ==
        line = re.sub(r'"([^"]+)"\.Equals\(([^)]+)\)\s*==\s*true', r'\2 == QStringLiteral("\1")', line)
        line = re.sub(r'"([^"]+)"\.Equals\(([^)]+)\)', r'\2 == QStringLiteral("\1")', line)
        
        # Convert .StartsWith to .startsWith
        line = line.replace('.StartsWith(', '.startsWith(')
        line = line.replace('.startsWith(', '.startsWith(')
        
        # Convert .Substring to .mid
        line = re.sub(r'\.Substring\(([^,]+)\)', r'.mid(\1)', line)
        line = re.sub(r'\.Substring\(([^,]+),\s*([^)]+)\)', r'.mid(\1, \2)', line)
        
        # Convert .Length to .length()
        line = line.replace('.Length', '.length()')
        line = line.replace('.length()', '.length()')
        
        # Convert .ToUpper to .toUpper()
        line = line.replace('.ToUpper()', '.toUpper()')
        
        # Convert .ContainsKey to .contains
        line = line.replace('.ContainsKey(', '.contains(')
        
        # Convert .CompareTo to .compare
        line = line.replace('.CompareTo(', '.compare(')
        
        # Convert .Add for lists/maps
        line = line.replace('.Add(', '.append(')
        line = line.replace('.Clear()', '.clear()')
        
        # Convert .Count to .count() or .size()
        line = line.replace('.Count', '.count()')
        
        # Convert DateTime.Now to QDateTime::currentDateTime()
        line = line.replace('DateTime.Now', 'QDateTime::currentDateTime()')
        line = line.replace('.Year', '.date().year()')
        line = line.replace('.Month', '.date().month()')
        line = line.replace('.Day', '.date().day()')
        line = line.replace('.Hour', '.time().hour()')
        line = line.replace('.Minute', '.time().minute()')
        line = line.replace('.Second', '.time().second()')
        
        # Convert new Random to QRandomGenerator
        line = re.sub(r'new\s+Random\((.*?)\)', r'QRandomGenerator(static_cast<quint32>(\1))', line)
        line = line.replace('.Next(', '.bounded(')
        
        # Convert Convert.ToString to QString::number
        line = re.sub(r'Convert\.ToString\((.*?)\)', r'QString::number(\1)', line)
        
        # Convert Environment.Exit to qApp->exit
        line = line.replace('Environment.Exit(0);', 'QCoreApplication::exit(0);')
        
        # Convert FileInfo
        if 'FileInfo' in line:
            line = re.sub(r'FileInfo\s+\w+\s*=\s*new\s+FileInfo\((.*?)\);', r'QFileInfo fileInfo(\1);', line)
            line = re.sub(r'new\s+FileInfo\((.*?)\)', r'QFileInfo(\1)', line)
        
        # Convert .Exists to .exists()
        line = line.replace('.Exists == true', '.exists()')
        line = line.replace('.Exists', '.exists()')
        
        # Convert && and ||
        line = line.replace('&&', '&&')
        line = line.replace('||', '||')
        
        # Convert ns.getArg to ns->getArg
        line = line.replace('ns.getArg(', 'ns->getArg(')
        line = line.replace('ns.getArgSize(', 'ns->getArgSize(')
        line = line.replace('ns.parseArgs(', 'ns->parseArgs(')
        line = line.replace('ns.nd.', 'ns->nd.')
        line = line.replace('ns.tn.', 'ns->tn.')
        line = line.replace('ns.error(', 'ns->error(')
        line = line.replace('ns.makeLineRest(', 'ns->makeLineRest(')
        line = line.replace('ns.setMsRest(', 'ns->setMsRest(')
        line = line.replace('ns.lineRest', 'ns->lineRest')
        line = line.replace('ns.readLine(', 'ns->readLine(')
        line = line.replace('ns.gotoLabel(', 'ns->gotoLabel(')
        line = line.replace('ns.setFilePointer(', 'ns->setFilePointer(')
        line = line.replace('ns.backHistory(', 'ns->backHistory(')
        line = line.replace('ns.loadLocalData(', 'ns->loadLocalData(')
        line = line.replace('ns.saveLocalData(', 'ns->saveLocalData(')
        line = line.replace('ns.loadGlobalData(', 'ns->loadGlobalData(')
        line = line.replace('ns.selectWait(', 'ns->selectWait(')
        line = line.replace('ns.storageState', 'ns->storageState')
        line = line.replace('ns.exitFlag', 'ns->exitFlag')
        line = line.replace('ns.argCont', 'ns->argCont')
        line = line.replace('ns.path', 'ns->path')
        
        # Convert null to nullptr
        line = line.replace(' == null', ' == nullptr')
        line = line.replace(' != null', ' != nullptr')
        line = line.replace('= null', '= nullptr')
        
        # Convert true/false to true/false (same in C++)
        # line = line.replace('true', 'true')
        # line = line.replace('false', 'false')
        
        # Convert this. to this-> (but there shouldn't be many)
        line = line.replace('this.', 'this->')
        
        # Convert string concatenation with +
        # Keep as is since QString supports +
        
        # Convert new NsButton to new NsButton
        line = line.replace('new NsButton(', 'new NsButton(')
        line = line.replace('new NsSelect(', 'new NsSelect(')
        line = line.replace('new NsEffect(', 'new NsEffect(')
        line = line.replace('new NsShell(', 'new NsShell(')
        line = line.replace('new NsText(', 'new NsText(')
        
        # Convert array access
        # Keep as is since C++ also uses []
        
        # Convert StringBuilder
        line = line.replace('new StringBuilder(', 'QString(')
        line = line.replace(').ToString()', ')')
        
        # Convert Encoding.GetEncoding
        line = re.sub(r'Encoding\.GetEncoding\("[^"]+"\)\.GetString\(([^,]+),\s*([^,]+),\s*([^)]+)\)', r'QString::fromLocal8Bit((const char*)\1 + \2, \3 - \2)', line)
        
        # Convert RandomAccessFile
        line = line.replace('new RandomAccessFile(', 'new QFile(')
        
        # Remove C# usings
        if line.strip().startswith('using '):
            continue
        
        # Remove namespace declarations
        if 'namespace tukineko' in line:
            continue
        if line.strip() == '{':
            continue
        if line.strip() == '}':
            continue
        
        # Skip class declaration
        if 'public class' in line:
            continue
        
        # Skip NScripter instance declaration
        if 'NScripter ns = NScripter.getInstance();' in line or 'NScripter ns=NScripter.getInstance();' in line:
            continue
        
        # Skip @Override comments
        if '@Override' in line:
            continue
        
        # Skip public override bool check
        if 'public override bool check(' in line:
            continue
        
        # Skip public override void execute
        if 'public override void execute()' in line:
            continue
        
        result.append(line)
    
    return '\n'.join(result)

def generate_derived_class(class_info, output_dir, subdir):
    class_name = class_info['class_name']
    base_class = class_info['base_class']
    command_name = class_info['command_name']
    uses_startswith = class_info['uses_startswith']
    body = class_info['body']
    has_ns = class_info['has_ns']
    
    guard = to_guard(class_name)
    base_header = f"../{base_class.lower()}.h"
    
    # For base classes in the same directory, adjust path
    if base_class in ['ECommand', 'FCommand', 'FECommand', 'SECommand', 'SFCommand', 'SFECommand', 'VECommand', 'VFECommand']:
        base_header = f"{base_class.lower()}.h"
    
    header_file = f"{class_name.lower()}.h"
    
    # Generate header
    if has_ns:
        h_content = DERIVED_H_TEMPLATE.format(
            guard=guard,
            class_name=class_name,
            base_class=base_class,
            base_header=base_header
        )
    else:
        # No NScripter instance needed
        h_content = f"""#ifndef {guard}_H
#define {guard}_H

#include "{base_header}"

class {class_name} : public {base_class}
{{
public:
    {class_name}();
    ~{class_name}() override;

    bool check(const QString &str) override;
    void execute() override;
}};

#endif // {guard}_H
"""
    
    # Generate cpp
    converted_body = convert_body(body, class_info)
    
    if uses_startswith:
        check_method = STARTSWITH_CHECK_TEMPLATE.format(
            class_name=class_name,
            command_name=command_name
        )
    else:
        check_method = f"""bool {class_name}::check(const QString &str)
{{
    return checkCommand(str, QStringLiteral("{command_name}"));
}}
"""
    
    if has_ns:
        cpp_content = f"""#include "{header_file}"

{class_name}::{class_name}()
    : ns(NScripter::getInstance())
{{
}}

{class_name}::~{class_name}()
{{
}}

{check_method}

void {class_name}::execute()
{{
    debug(QStringLiteral("[{base_class}] {command_name}"));
{converted_body}
}}
"""
    else:
        cpp_content = f"""#include "{header_file}"

{class_name}::{class_name}()
{{
}}

{class_name}::~{class_name}()
{{
}}

{check_method}

void {class_name}::execute()
{{
    debug(QStringLiteral("[{base_class}] {command_name}"));
{converted_body}
}}
"""
    
    h_path = os.path.join(output_dir, header_file)
    cpp_path = os.path.join(output_dir, f"{class_name.lower()}.cpp")
    
    with open(h_path, 'w', encoding='utf-8') as f:
        f.write(h_content)
    with open(cpp_path, 'w', encoding='utf-8') as f:
        f.write(cpp_content)
    
    print(f"Generated: {h_path}")
    print(f"Generated: {cpp_path}")

def main():
    base_dir = r"c:\Users\admin\Documents\trae_projects\hello1\csharp\tukineko\nsdumper"
    output_base = r"c:\Users\admin\Documents\trae_projects\hello1\qt\tukineko\nsdumper"
    
    subdirs = ['ecmd', 'fcmd', 'fecmd', 'secmd', 'sfcmd', 'sfecmd', 'vecmd', 'vfecmd']
    
    # First generate base classes at the root of nsdumper
    base_classes = {
        'ECommand': 'ecmd',
        'FCommand': 'fcmd',
        'FECommand': 'fecmd',
        'SECommand': 'secmd',
        'SFCommand': 'sfcmd',
        'SFECommand': 'sfecmd',
        'VECommand': 'vecmd',
        'VFECommand': 'vfecmd'
    }
    
    # Generate base classes in their respective directories
    for base_name, subdir in base_classes.items():
        output_dir = os.path.join(output_base, subdir)
        generate_base_class(base_name, output_dir)
    
    # Generate derived classes
    for subdir in subdirs:
        cs_dir = os.path.join(base_dir, subdir)
        output_dir = os.path.join(output_base, subdir)
        
        for cs_file in glob.glob(os.path.join(cs_dir, '*.cs')):
            class_info = parse_cs_file(cs_file)
            if class_info and class_info['class_name'] not in base_classes:
                generate_derived_class(class_info, output_dir, subdir)
    
    print("\nDone! All files generated.")

if __name__ == '__main__':
    main()
