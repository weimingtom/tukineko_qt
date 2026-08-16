# C# to Qt C++ Conversion Summary

## Project Overview

This project is a conversion of a C# NScripter game engine implementation to Qt C++. The original C# code was located in the `csharp/` directory and has been converted to Qt C++ code in the `qt/` directory.

---

## File Statistics

| Type | Count |
|------|-------|
| Header Files (.h) | 210 |
| Implementation Files (.cpp) | 206 |
| Project Files (.pro, .txt) | 2 |
| **Total** | **418** |

---

## Directory Structure

```
qt/
├── main.cpp                          # Application entry point
├── MainWindow.h/.cpp                 # Main window (replaces MainForm.cs)
├── tukineko.pro                      # Qt qmake project file
├── CMakeLists.txt                    # CMake build file
│
├── java/                             # Java API compatibility layer
│   ├── io/                           # IO stream classes
│   │   ├── InputStream.h/.cpp
│   │   ├── OutputStream.h/.cpp
│   │   ├── FileInputStream.h/.cpp
│   │   ├── FileOutputStream.h/.cpp
│   │   ├── ByteArrayInputStream.h/.cpp
│   │   ├── ByteArrayOutputStream.h/.cpp
│   │   ├── ObjectInputStream.h/.cpp
│   │   ├── ObjectOutputStream.h/.cpp
│   │   ├── RandomAccessFile.h/.cpp
│   │   ├── File_.h/.cpp
│   │   └── IOException.h
│   │
│   ├── awt/                          # GUI abstraction classes
│   │   ├── Color_.h/.cpp
│   │   ├── Component.h/.cpp
│   │   ├── Dimension.h/.cpp
│   │   ├── FontMetrics.h/.cpp
│   │   ├── Frame.h/.cpp
│   │   ├── Graphics_.h/.cpp
│   │   ├── Image_.h/.cpp
│   │   ├── MediaTracker.h/.cpp
│   │   ├── Menu.h/.cpp
│   │   ├── Panel_.h/.cpp
│   │   ├── PopupMenu.h/.cpp
│   │   ├── Toolkit.h/.cpp
│   │   ├── event/                    # Event classes
│   │   │   ├── ActionEvent.h/.cpp
│   │   │   ├── ActionListener.h
│   │   │   ├── MouseEvent.h/.cpp
│   │   │   ├── MouseListener.h
│   │   │   ├── WindowAdapter.h/.cpp
│   │   │   └── WindowEvent.h/.cpp
│   │   └── image/                    # Image processing
│   │       ├── MemoryImageSource.h/.cpp
│   │       └── PixelGrabber.h/.cpp
│   │
│   └── lang/                         # Language base classes
│       ├── Thread_.h/.cpp
│       ├── Runtime.h/.cpp
│       ├── InterruptedException.h
│       └── NumberFormatException.h
│
├── tukineko/                         # Core game engine
│   ├── Tukineko.h/.cpp               # Entry point class
│   ├── NsWindow.h/.cpp               # Main game window
│   ├── NsActionListener.h/.cpp       # Action listener
│   │
│   ├── entry/                        # Data entity classes
│   │   ├── NsData.h/.cpp
│   │   ├── NsColor.h/.cpp
│   │   ├── NsText.h/.cpp
│   │   ├── NsSprite.h/.cpp
│   │   ├── NsShell.h/.cpp
│   │   ├── NsSelect.h/.cpp
│   │   ├── NsGosub.h/.cpp
│   │   ├── NsEffect.h/.cpp
│   │   └── NsButton.h/.cpp
│   │
│   ├── file/                         # File I/O classes
│   │   ├── NsaEntry.h/.cpp
│   │   ├── NsaFile.h/.cpp
│   │   ├── NsaInputStream.h/.cpp
│   │   ├── SarEntry.h/.cpp
│   │   ├── SarFile.h/.cpp
│   │   └── SarInputStream.h/.cpp
│   │
│   ├── global/                       # Global utility classes
│   │   ├── NsImage.h/.cpp
│   │   ├── NsImageCache.h/.cpp
│   │   ├── NsResource.h/.cpp
│   │   ├── NsThread.h/.cpp
│   │   ├── NsTimer.h/.cpp
│   │   └── NsValueStorage.h/.cpp
│   │
│   ├── parser/                       # Script parser
│   │   ├── NScripter.h/.cpp
│   │   └── Util.h/.cpp
│   │
│   └── nsdumper/                     # NScripter command implementations
│       ├── parser/
│       │   └── NSParser.h/.cpp
│       │
│       ├── ecmd/                     # Event commands (22 classes)
│       │   ├── ECommand.h/.cpp
│       │   ├── BtnCommand.h/.cpp
│       │   ├── BtndefCommand.h/.cpp
│       │   ├── BtnwaitCommand.h/.cpp
│       │   ├── Btnwait2Command.h/.cpp
│       │   ├── ClickCommand.h/.cpp
│       │   ├── ClickposCommand.h/.cpp
│       │   ├── DefineresetCommand.h/.cpp
│       │   ├── DelayCommand.h/.cpp
│       │   ├── GettimerCommand.h/.cpp
│       │   ├── InputstrCommand.h/.cpp
│       │   ├── LookbackflushCommand.h/.cpp
│       │   ├── ResetCommand.h/.cpp
│       │   ├── ResettimerCommand.h/.cpp
│       │   ├── RmodeCommand.h/.cpp
│       │   ├── SelectCommand.h/.cpp
│       │   ├── SelgosubCommand.h/.cpp
│       │   ├── SelnumCommand.h/.cpp
│       │   ├── SystemcallCommand.h/.cpp
│       │   ├── TextspeedCommand.h/.cpp
│       │   ├── TrapCommand.h/.cpp
│       │   ├── WaitCommand.h/.cpp
│       │   └── WaittimerCommand.h/.cpp
│       │
│       ├── fcmd/                     # File commands (4 classes)
│       │   ├── FCommand.h/.cpp
│       │   ├── GameCommand.h/.cpp
│       │   ├── IntlimitCommand.h/.cpp
│       │   └── SavenumberCommand.h/.cpp
│       │
│       ├── fecmd/                    # Flow control commands (29 classes)
│       │   ├── FECommand.h/.cpp
│       │   ├── AddCommand.h/.cpp
│       │   ├── AtoiCommand.h/.cpp
│       │   ├── CmpCommand.h/.cpp
│       │   ├── DateCommand.h/.cpp
│       │   ├── DecCommand.h/.cpp
│       │   ├── DivCommand.h/.cpp
│       │   ├── EndCommand.h/.cpp
│       │   ├── GetiniCommand.h/.cpp
│       │   ├── GetregCommand.h/.cpp
│       │   ├── GosubCommand.h/.cpp
│       │   ├── GotoCommand.h/.cpp
│       │   ├── IfCommand.h/.cpp
│       │   ├── IncCommand.h/.cpp
│       │   ├── ItoaCommand.h/.cpp
│       │   ├── JumpbCommand.h/.cpp
│       │   ├── JumpfCommand.h/.cpp
│       │   ├── LoadgameCommand.h/.cpp
│       │   ├── ModCommand.h/.cpp
│       │   ├── MovCommand.h/.cpp
│       │   ├── MulCommand.h/.cpp
│       │   ├── NotifCommand.h/.cpp
│       │   ├── ReturnCommand.h/.cpp
│       │   ├── RndCommand.h/.cpp
│       │   ├── Rnd2Command.h/.cpp
│       │   ├── SavegameCommand.h/.cpp
│       │   ├── SaveoffCommand.h/.cpp
│       │   ├── SaveonCommand.h/.cpp
│       │   ├── SkipCommand.h/.cpp
│       │   ├── SubCommand.h/.cpp
│       │   └── TimeCommand.h/.cpp
│       │
│       ├── secmd/                    # Setting commands (4 classes)
│       │   ├── SECommand.h/.cpp
│       │   ├── AbssetcursorCommand.h/.cpp
│       │   ├── SetcursorCommand.h/.cpp
│       │   └── SetwindowCommand.h/.cpp
│       │
│       ├── sfcmd/                    # System function commands (33 classes)
│       │   ├── SFCommand.h/.cpp
│       │   ├── ArcCommand.h/.cpp
│       │   ├── BgaliaCommand.h/.cpp
│       │   ├── CdfadeoutCommand.h/.cpp
│       │   ├── ClickstrCommand.h/.cpp
│       │   ├── ClickvoiceCommand.h/.cpp
│       │   ├── DefSpeedCommand.h/.cpp
│       │   ├── DefaultfontCommand.h/.cpp
│       │   ├── DsoundCommand.h/.cpp
│       │   ├── EffectCommand.h/.cpp
│       │   ├── EffectblankCommand.h/.cpp
│       │   ├── FilelogCommand.h/.cpp
│       │   ├── GlobalonCommand.h/.cpp
│       │   ├── HumanzCommand.h/.cpp
│       │   ├── KillmenuCommand.h/.cpp
│       │   ├── LabellogCommand.h/.cpp
│       │   ├── LookbackbuttonCommand.h/.cpp
│       │   ├── LookbackcolorCommand.h/.cpp
│       │   ├── LookbackvoiceCommand.h/.cpp
│       │   ├── MenuselectcolorCommand.h/.cpp
│       │   ├── MenuselectvoiceCommand.h/.cpp
│       │   ├── MenusetwindowCommand.h/.cpp
│       │   ├── NsaCommand.h/.cpp
│       │   ├── NumaliasCommand.h/.cpp
│       │   ├── RlookbackCommand.h/.cpp
│       │   ├── RmenuCommand.h/.cpp
│       │   ├── RoffCommand.h/.cpp
│       │   ├── SavenameCommand.h/.cpp
│       │   ├── SelectcolorCommand.h/.cpp
│       │   ├── SelectvoiceCommand.h/.cpp
│       │   ├── SoundpressplginCommand.h/.cpp
│       │   ├── SpiCommand.h/.cpp
│       │   ├── StraliasCommand.h/.cpp
│       │   ├── TransmodeCommand.h/.cpp
│       │   ├── UnderlineCommand.h/.cpp
│       │   └── VersionstrCommand.h/.cpp
│       │
│       ├── sfecmd/                   # System function extensions (5 classes)
│       │   ├── SFECommand.h/.cpp
│       │   ├── CaptionCommand.h/.cpp
│       │   ├── GetversionCommand.h/.cpp
│       │   ├── MousecursorCommand.h/.cpp
│       │   └── WindoweffectCommand.h/.cpp
│       │
│       ├── vecmd/                    # Visual effect commands (36 classes)
│       │   ├── VECommand.h/.cpp
│       │   ├── AutoclickCommand.h/.cpp
│       │   ├── AviCommand.h/.cpp
│       │   ├── BgCommand.h/.cpp
│       │   ├── BltCommand.h/.cpp
│       │   ├── BrCommand.h/.cpp
│       │   ├── ClCommand.h/.cpp
│       │   ├── CspCommand.h/.cpp
│       │   ├── DwaveCommand.h/.cpp
│       │   ├── DwaveloopCommand.h/.cpp
│       │   ├── DwavestopCommand.h/.cpp
│       │   ├── ErasetextwindowCommand.h/.cpp
│       │   ├── LdCommand.h/.cpp
│       │   ├── LocateCommand.h/.cpp
│       │   ├── LspCommand.h/.cpp
│       │   ├── LsphCommand.h/.cpp
│       │   ├── MenuclickdefCommand.h/.cpp
│       │   ├── MenuclickpageCommand.h/.cpp
│       │   ├── MenufullCommand.h/.cpp
│       │   ├── MenuwindowCommand.h/.cpp
│       │   ├── MonocroCommand.h/.cpp
│       │   ├── Mp3Command.h/.cpp
│       │   ├── Mp3loopCommand.h/.cpp
│       │   ├── MspCommand.h/.cpp
│       │   ├── NegaCommand.h/.cpp
│       │   ├── OfscpyCommand.h/.cpp
│       │   ├── PlayCommand.h/.cpp
│       │   ├── PlayonceCommand.h/.cpp
│       │   ├── PlaystopCommand.h/.cpp
│       │   ├── PrintCommand.h/.cpp
│       │   ├── PuttextCommand.h/.cpp
│       │   ├── QuakexCommand.h/.cpp
│       │   ├── QuakeyCommand.h/.cpp
│       │   ├── StopCommand.h/.cpp
│       │   ├── TalCommand.h/.cpp
│       │   ├── TextclearCommand.h/.cpp
│       │   ├── TextoffCommand.h/.cpp
│       │   ├── TextonCommand.h/.cpp
│       │   ├── VspCommand.h/.cpp
│       │   ├── WaveCommand.h/.cpp
│       │   ├── WaveloopCommand.h/.cpp
│       │   └── WavestopCommand.h/.cpp
│       │
│       └── vfecmd/                   # Visual function extensions (2 classes)
│           ├── VFECommand.h/.cpp
│           └── MesboxCommand.h/.cpp
```

---

## Type Mapping Reference

| C# Type | Qt C++ Type | Notes |
|---------|-------------|-------|
| `String` | `QString` | Unicode string support |
| `bool` | `bool` | No change |
| `int` | `int` | No change |
| `uint` | `quint32` | Qt unsigned integer |
| `byte[]` | `QByteArray` | Binary data buffer |
| `List<T>` | `QList<T>` | Dynamic array |
| `Dictionary<K,V>` | `QMap<K,V>` | Key-value map |
| `Thread` | `QThread` | Threading support |
| `Timer` | `QTimer` | Timer with signals/slots |
| `Graphics` | `QPainter` | 2D drawing |
| `Image`/`Bitmap` | `QImage` | Image manipulation |
| `Color` | `QColor` | Color representation |
| `Font` | `QFont` | Font handling |
| `Stream` | `QIODevice` | Base I/O device |
| `FileStream` | `QFile` | File operations |
| `Exception` | `std::runtime_error` | Error handling |

---

## Build Instructions

### Using qmake

```bash
cd qt
qmake tukineko.pro
make
```

### Using CMake

```bash
cd qt
mkdir build && cd build
cmake ..
cmake --build .
```

---

## Key Conversion Notes

1. **Java Compatibility Layer**: The original C# code included a Java API compatibility layer. These classes have been converted to use Qt equivalents internally while maintaining the original API structure.

2. **Graphics System**: System.Drawing has been replaced with QPainter/QImage. All drawing operations now use Qt's coordinate system.

3. **Threading**: System.Threading has been replaced with QThread. Thread sleep operations use QThread::msleep().

4. **File I/O**: .NET file streams have been replaced with QFile and QDataStream. Byte order handling is preserved.

5. **String Handling**: All string operations use QString with appropriate encoding support (including Shift-JIS via QTextCodec).

6. **Event System**: WinForms events have been converted to Qt's signal/slot mechanism where appropriate.

7. **Memory Management**: Qt's parent-child object hierarchy is used for automatic memory management.

---

## Original C# Source

The original C# source files are located in:
- `csharp/` - Root directory with MainForm.cs, Program.cs
- `csharp/tukineko/` - Core engine classes
- `csharp/java/` - Java compatibility layer

---

## Conversion Date

2026-06-01
