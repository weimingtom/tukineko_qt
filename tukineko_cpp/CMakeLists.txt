cmake_minimum_required(VERSION 3.16)
project(tukineko LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})

# Main application files
set(APP_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

# Java AWT compatibility layer
set(JAWT_SOURCES
    java_awt/color_.h
    java_awt/color_.cpp
    java_awt/component.h
    java_awt/component.cpp
    java_awt/panel_.h
    java_awt/panel_.cpp
    java_awt/graphics_.h
    java_awt/graphics_.cpp
    java_awt/image_.h
    java_awt/image_.cpp
    java_awt/mouse_event.h
    java_awt/mouse_listener.h
    java_awt/dimension.h
    java_awt/font_metrics.h
    java_awt/font_metrics.cpp
    java_awt/toolkit.h
    java_awt/toolkit.cpp
    java_awt/java_awt.h
)

# Java IO compatibility layer
set(JIO_SOURCES
    java_io/input_stream.h
    java_io/input_stream.cpp
    java_io/output_stream.h
    java_io/output_stream.cpp
    java_io/file_.h
    java_io/file_.cpp
    java_io/random_access_file.h
    java_io/random_access_file.cpp
    java_io/object_input_stream.h
    java_io/object_input_stream.cpp
    java_io/object_output_stream.h
    java_io/object_output_stream.cpp
    java_io/io_exception.h
    java_io/java_io.h
)

# Java lang compatibility layer
set(JLANG_SOURCES
    java_lang/runtime.h
    java_lang/runtime.cpp
    java_lang/thread_.h
    java_lang/thread_.cpp
    java_lang/java_lang.h
)

# Tukineko engine
set(TUKINEKO_SOURCES
    tukineko/tukineko.h      # Tukineko class
    tukineko/tukineko.cpp
    tukineko/nswindow.h
    tukineko/nswindow.cpp
    tukineko/nsdata.h
    tukineko/nsdata.cpp
    tukineko/nsresource.h
    tukineko/nsresource.cpp
    tukineko/nsimagecache.h
    tukineko/nsimagecache.cpp
    tukineko/nsa_file.h
    tukineko/nsa_file.cpp
    tukineko/sar_file.h
    tukineko/sar_file.cpp
    tukineko/nscripter.h
    tukineko/nscripter.cpp
    tukineko/nstext.h
    tukineko/nstext.cpp
    tukineko/nsbutton.h
    tukineko/nsbutton.cpp
    tukineko/nssprite.h
    tukineko/nssprite.cpp
    tukineko/nseffect.h
    tukineko/nseffect.cpp
    tukineko/tukineko.h
)

add_executable(tukineko WIN32
    ${APP_SOURCES}
    ${JAWT_SOURCES}
    ${JIO_SOURCES}
    ${JLANG_SOURCES}
    ${TUKINEKO_SOURCES}
)

target_link_libraries(tukineko Qt5::Widgets Qt5::Core Qt5::Gui)

# Optional: Add resources if they exist
if(EXISTS ${CMAKE_SOURCE_DIR}/resources.qrc)
    target_sources(tukineko PRIVATE resources.qrc)
endif()
