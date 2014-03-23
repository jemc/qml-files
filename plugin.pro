
TEMPLATE = lib

CONFIG += plugin \
          c++11
QT += qml quick

TARGET = $$qtLibraryTarget(filesplugin)
uri = org.jemc.qml.Files

DESTDIR  = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
SRCDIR   = $$PWD/src
BUILDDIR = $$PWD/build

HEADERS += $$SRCDIR/filesplugin.h           \
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

OBJECTS_DIR = $$BUILDDIR/.obj
MOC_DIR     = $$BUILDDIR/.moc
RCC_DIR     = $$BUILDDIR/.rcc
UI_DIR      = $$BUILDDIR/.ui

target.path  = $$DESTDIR
qmldir.files = $$PWD/qmldir
qmldir.path  = $$DESTDIR

OTHER_FILES += $$SRCDIR/qmldir

INSTALLS    += target qmldir

# Copy the qmldir file to the same folder as the plugin binary
QMAKE_POST_LINK += $$QMAKE_COPY $$replace($$list($$quote($$SRCDIR/qmldir) $$DESTDIR), /, $$QMAKE_DIR_SEP)
