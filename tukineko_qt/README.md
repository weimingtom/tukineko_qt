# Tukineko Qt5

NScripter 引擎的 Qt5 C++ 移植版本，将原始 C# 代码转换为 Qt5 C++。
by CodeBuddy and MiniMax M2.7

## 构建方式

### 使用 qmake

```bash
cd qt
qmake tukineko.pro
make
# Windows: nmake 或 jom
# macOS: make
# Linux: make
```

可执行文件输出到 `qt/bin/` 目录。

### 使用 CMake

```bash
cd qt
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

可执行文件输出到 `qt/bin/` 目录。

---

## C# → Qt5 C++ 转换映射表

| C# 组件 | Qt5 C++ 映射 |
|---------|-------------|
| `System.Windows.Forms.Control` | `QWidget` |
| `System.Windows.Forms.Form` | `QMainWindow` |
| 事件处理 (`MouseListener`, `ActionListener`) | Qt 信号槽 (`signals`/`slots`) |
| `System.Drawing.Graphics` | `QPainter` |
| `System.Collections.Generic.List<T>` | `QVector<T>` |
| `System.Collections.Generic.Dictionary<K,V>` | `QMap<K, V>` |
| `System.String` | `QString` |
| `System.Threading.Thread` | `QThread` |
| `FileInputStream` / `FileOutputStream` | `QFile` + `QDataStream` |
| `RandomAccessFile` | 自定义 `RandomAccessFile` |
| `ArrayList` | `QVector<void*>` |
| `Hashtable` | `QMap<QString, void*>` |

## 项目结构

```
qt/
├── CMakeLists.txt              # CMake 构建配置
├── tukineko.pro               # qmake 项目文件
├── main.cpp                   # 程序入口
├── mainwindow.h/cpp           # 主窗口
├── java/                      # Java AWT 模拟层
│   ├── awt/                   # UI 组件
│   │   ├── component.h/cpp   # 组件基类
│   │   ├── frame.h/cpp       # 窗口框架
│   │   ├── panel.h/cpp       # 面板
│   │   ├── graphics.h/cpp    # 绘图上下文
│   │   ├── color.h/cpp       # 颜色
│   │   ├── image.h/cpp       # 图像
│   │   ├── dimension.h/cpp   # 尺寸
│   │   ├── fontmetrics.h/cpp # 字体度量
│   │   ├── menu.h/cpp        # 菜单
│   │   ├── popupmenu.h/cpp   # 弹出菜单
│   │   ├── toolkit.h/cpp     # 工具包
│   │   ├── mediatracker.h/cpp # 媒体追踪器
│   │   ├── event/            # 事件处理
│   │   │   ├── mouseevent.h/cpp
│   │   │   ├── mouselistener.h/cpp
│   │   │   ├── actionevent.h/cpp
│   │   │   ├── actionlistener.h/cpp
│   │   │   ├── windowevent.h/cpp
│   │   │   └── windowadapter.h/cpp
│   │   └── image/             # 图像处理
│   │       ├── memoryimagesource.h/cpp
│   │       └── pixelgrabber.h/cpp
│   ├── io/                    # IO 流
│   │   ├── inputstream.h/cpp
│   │   ├── outputstream.h/cpp
│   │   ├── bytearrayinputstream.h/cpp
│   │   ├── bytearrayoutputstream.h/cpp
│   │   ├── fileinputstream.h/cpp
│   │   ├── fileoutputstream.h/cpp
│   │   ├── file_.h/cpp
│   │   └── randomaccessfile.h/cpp
│   └── lang/                  # 语言模拟
│       ├── thread.h/cpp
│       └── runtime.h/cpp
└── tukineko/                  # 核心业务逻辑
    ├── nswindow.h/cpp         # 主窗口 (NScripter)
    ├── nsactionlistener.h/cpp # 动作监听
    ├── tukineko.h/cpp         # 引擎主类
    ├── entry/                 # 数据结构
    │   ├── nsdata.h/cpp
    │   ├── nstext.h/cpp
    │   ├── nsbutton.h/cpp
    │   ├── nscolor.h/cpp
    │   ├── nseffect.h/cpp
    │   ├── nssselect.h/cpp
    │   ├── nsssprite.h/cpp
    │   ├── nssprite.h/cpp
    │   └── nsshell.h/cpp
    ├── global/                # 全局管理
    │   ├── nsimage.h/cpp
    │   ├── nsresource.h/cpp
    │   ├── nsimagecache.h/cpp
    │   ├── nstimer.h/cpp
    │   ├── nsthread.h/cpp
    │   └── nsvaluestorage.h/cpp
    ├── file/                  # 文件格式
    │   ├── sarfile.h/cpp
    │   ├── sarentry.h/cpp
    │   ├── sarinputstream.h/cpp
    │   ├── nsafile.h/cpp
    │   ├── nsaentry.h/cpp
    │   └── nsainputstream.h/cpp
    ├── parser/                # 脚本解析
    │   ├── nsparser.h/cpp
    │   ├── nscripter.h/cpp
    │   └── util.h/cpp
    └── nsdumper/              # 命令处理
        ├── parser/
        │   └── nsparserimpl.h/cpp
        ├── fcmd/              # 定义阶段命令
        │   ├── fcommand.h/cpp
        │   ├── gamecommand.h/cpp
        │   ├── intlimitcommand.h/cpp
        │   └── savenumbercommand.h/cpp
        ├── fecmd/             # 执行阶段命令
        │   ├── addcommand.h/cpp
        │   ├── atoicommand.h/cpp
        │   ├── cmpcommand.h/cpp
        │   ├── datecommand.h/cpp
        │   ├── deccommand.h/cpp
        │   ├── divcommand.h/cpp
        │   ├── endcommand.h/cpp
        │   ├── getinicommand.h/cpp
        │   ├── getregcommand.h/cpp
        │   ├── gosubcommand.h/cpp
        │   ├── ifcommand.h/cpp
        │   ├── inccommand.h/cpp
        │   ├── itoacommand.h/cpp
        │   ├── jmpbcommand.h/cpp
        │   ├── jmpfcommand.h/cpp
        │   ├── loadgamecommand.h/cpp
        │   ├── modcommand.h/cpp
        │   ├── movcommand.h/cpp
        │   ├── mulcommand.h/cpp
        │   ├── notifcommand.h/cpp
        │   ├── returncommand.h/cpp
        │   ├── rndcommand.h/cpp
        │   ├── rnd2command.h/cpp
        │   ├── savegamecommand.h/cpp
        │   ├── savecmmand.h/cpp
        │   ├── skipcommand.h/cpp
        │   ├── subcommand.h/cpp
        │   └── timecommand.h/cpp
        └── cmd/               # 系统命令
            ├── ecommand.h/cpp
            ├── btncommand.h/cpp
            ├── btndefcommand.h/cpp
            ├── btnwaitcommand.h/cpp
            ├── btnwait2command.h/cpp
            ├── clickcommand.h/cpp
            ├── clickposcommand.h/cpp
            ├── defineresetcommand.h/cpp
            ├── delaycommand.h/cpp
            ├── gettimercommand.h/cpp
            ├── inputstrcommand.h/cpp
            ├── lookbackflushcommand.h/cpp
            ├── resetcommand.h/cpp
            ├── resettimercommand.h/cpp
            ├── rmodecommand.h/cpp
            ├── selectcommand.h/cpp
            ├── selgosubcommand.h/cpp
            ├── selnumcommand.h/cpp
            ├── systemcallcommand.h/cpp
            ├── textspeedcommand.h/cpp
            ├── trapcommand.h/cpp
            ├── waitcommand.h/cpp
            └── waittimercommand.h/cpp
```

## 主要功能

- NScripter 脚本引擎核心逻辑
- 双缓冲渲染 (paintB/paintF)
- 鼠标事件处理
- SAR/NSA 归档文件支持
- 图像缓存 (LRU)
- 文字显示和选择系统
- 存档/读档功能
