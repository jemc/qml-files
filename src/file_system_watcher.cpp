
#include "file_system_watcher.h"


bool FileSystemWatcher::addPath(const QString & path)
{ return qwatcher.addPath(path); };

QStringList FileSystemWatcher::addPaths(const QStringList & paths)
{ return qwatcher.addPaths(paths); };

QStringList FileSystemWatcher::directories()
{ return qwatcher.directories(); };

QStringList FileSystemWatcher::files()
{ return qwatcher.files(); };

bool FileSystemWatcher::removePath(const QString & path)
{ return qwatcher.removePath(path); };

QStringList FileSystemWatcher::removePaths(const QStringList & paths)
{ return qwatcher.removePaths(paths); };
