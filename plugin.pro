
TEMPLATE = lib

CONFIG += qt plugin c++11
QT     += qml quick

TARGET = $$qtLibraryTarget(qml-files)
uri = org.jemc.qml.Files

TARGETDIR = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
SRCDIR    = $$PWD/src
DESTDIR   = $$PWD/build/native

android {
  VENDORDIR = $$PWD/vendor/prefix/$(TOOLCHAIN_NAME)
  DESTDIR   = $$PWD/build/$(TOOLCHAIN_NAME)
  QMAKE_LIBDIR += $$VENDORDIR/lib
  QMAKE_INCDIR += $$VENDORDIR/include
}

HEADERS += $$SRCDIR/qml-files.h             \
           $$SRCDIR/dir.h                   \
           $$SRCDIR/file_info.h             \
           $$SRCDIR/file_system_watcher.h   \
           $$SRCDIR/standard_paths.h        \
           $$SRCDIR/file.h                  

SOURCES += $$SRCDIR/dir.cpp                 \
           $$SRCDIR/file_info.cpp           \
           $$SRCDIR/file_system_watcher.cpp \
           $$SRCDIR/standard_paths.cpp      \
           $$SRCDIR/file.cpp                

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR     = $$DESTDIR/.moc
RCC_DIR     = $$DESTDIR/.rcc
UI_DIR      = $$DESTDIR/.ui

target.path   = $$TARGETDIR
qmldir.files += $$SRCDIR/qmldir $$SRCDIR/qml/*
qmldir.path   = $$TARGETDIR

INSTALLS += target qmldir
