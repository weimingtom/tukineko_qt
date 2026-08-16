# Tukineko Qt5 Port

This is a Qt5 C++ port of the Tukineko NScripter engine, originally written in C#.

## Project Structure

```
cpp/
├── CMakeLists.txt          # CMake build configuration
├── main.cpp                # Application entry point
├── mainwindow.h/cpp        # Main Qt window (replaces MainForm)
├── java_awt/               # Java AWT compatibility layer
│   ├── color_.h/cpp       # Color class
│   ├── component.h/cpp    # Component base class
│   ├── panel_.h/cpp       # Panel class
│   ├── graphics_.h/cpp    # Graphics context
│   ├── image_.h/cpp       # Image class
│   ├── mouse_event.h      # Mouse event struct
│   ├── mouse_listener.h   # Mouse listener interface
│   ├── dimension.h        # Dimension class
│   ├── font_metrics.h/cpp # Font metrics
│   └── toolkit.h/cpp      # Toolkit class
├── java_io/               # Java IO compatibility layer
│   ├── input_stream.h/cpp # InputStream class
│   ├── output_stream.h/cpp # OutputStream class
│   ├── file_.h/cpp        # File class
│   ├── random_access_file.h/cpp
│   ├── object_input_stream.h/cpp
│   ├── object_output_stream.h/cpp
│   └── io_exception.h
├── java_lang/             # Java lang compatibility layer
│   ├── runtime.h/cpp     # Runtime class
│   └── thread_.h/cpp      # Thread class
└── tukineko/              # Core engine
    ├── tukineko.h/cpp     # Main entry
    ├── nswindow.h/cpp     # Game window
    ├── nsdata.h/cpp       # Game data/state
    ├── nsresource.h/cpp   # Resource loader
    ├── nsimagecache.h/cpp # Image cache (LRU)
    ├── nsa_file.h/cpp     # NSA archive reader
    ├── sar_file.h/cpp     # SAR archive reader
    ├── nscripter.h/cpp    # Script parser
    ├── nstext.h/cpp       # Text data
    ├── nsbutton.h/cpp     # Button data
    ├── nssprite.h/cpp     # Sprite data
    └── nseffect.h/cpp     # Effect data
```

## Building

### Prerequisites
- Qt5 SDK (>= 5.15)
- CMake (>= 3.16)
- C++17 compatible compiler

### Build Steps

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake .. -G "MinGW Makefiles"  # or "Ninja", "Visual Studio", etc.

# Build
cmake --build . --config Release

# Run
./tukineko
```

## C# to Qt5 Mappings

| C# (WinForms) | Qt5 Equivalent |
|--------------|----------------|
| `Form` | `QMainWindow` |
| `Panel` | `QWidget` |
| `Graphics` | `QPainter` |
| `Bitmap` | `QImage` / `QPixmap` |
| `Color` | `QColor` |
| `Timer` | `QTimer` |
| `Thread` | `QThread` |
| `MenuStrip` | `QMenuBar` |
| `Menu` | `QMenu` |
| `MouseEvent` | `QMouseEvent` |

## Features

- NScripter script support
- NSA/SAR archive reading
- Image caching with LRU
- Double-buffered rendering
- Sprite and background management
- Text rendering with color support
- Button/click detection

## Usage

Place your game files (NSCRIPT.DAT, NSA archives, etc.) in the same directory as the executable.

## License

Original Tukineko project license applies.
