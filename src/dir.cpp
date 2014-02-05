
#include "dir.h"


QObject* Dir::qmlAttachedProperties(QObject* object)
{
    return new DirAttached(object);
}


QString Dir::absoluteFilePath(const QString & fileName) const
{ return qdir.absoluteFilePath(fileName); };

QString Dir::absolutePath() const
{ return qdir.absolutePath(); };

QString Dir::canonicalPath() const
{ return qdir.canonicalPath(); };

bool Dir::cd(const QString & dirName)
{ return qdir.cd(dirName); };

bool Dir::cdUp()
{ return qdir.cdUp(); };

uint Dir::count() const
{ return qdir.count(); };

QString Dir::dirName() const
{ return qdir.dirName(); };

// QFileInfoList Dir::entryInfoList(const QStringList & nameFilters, QDir::Filters filters = NoFilter, SortFlags sort = NoSort) const

// QFileInfoList Dir::entryInfoList(QDir::Filters filters = NoFilter, SortFlags sort = NoSort) const

QStringList Dir::entryList() const
{ return qdir.entryList(); };

bool Dir::exists(const QString & name) const
{ return qdir.exists(name); };

bool Dir::exists() const
{ return qdir.exists(); };

QString Dir::filePath(const QString & fileName) const
{ return qdir.filePath(fileName); };

Dir::Filters Dir::filter() const
{ return (Dir::Filters)(uint)qdir.filter(); };

bool Dir::isAbsolute() const
{ return qdir.isAbsolute(); };

bool Dir::isReadable() const
{ return qdir.isReadable(); };

bool Dir::isRelative() const
{ return qdir.isRelative(); };

bool Dir::isRoot() const
{ return qdir.isRoot(); };

bool Dir::makeAbsolute()
{ return qdir.makeAbsolute(); };

bool Dir::mkdir(const QString & dirName) const
{ return qdir.mkdir(dirName);  };

bool Dir::mkpath(const QString & dirPath) const
{ return qdir.mkpath(dirPath); };

QStringList Dir::nameFilters() const
{ return qdir.nameFilters(); };

QString Dir::path() const
{ return qdir.path(); };

void Dir::refresh() const
{ return qdir.refresh(); };

QString Dir::relativeFilePath(const QString & fileName) const
{ return qdir.relativeFilePath(fileName); };

bool Dir::remove(const QString & fileName)
{ return qdir.remove(fileName); };

bool Dir::removeRecursively()
{ return qdir.removeRecursively(); };

bool Dir::rename(const QString & oldName, const QString & newName)
{ return qdir.rename(oldName, newName); };

bool Dir::rmdir(const QString & dirName) const
{ return qdir.rmdir(dirName); };

bool Dir::rmpath(const QString & dirPath) const
{ return qdir.rmpath(dirPath); };

void Dir::setFilter(Dir::Filters filters)
{ return qdir.setFilter((QDir::Filters)(uint)filters); };

void Dir::setNameFilters(const QStringList & nameFilters)
{ return qdir.setNameFilters(nameFilters); };

void Dir::setPath(const QString & path)
{ return qdir.setPath(path); };

void Dir::setSorting(Dir::SortFlags sort)
{ return qdir.setSorting((QDir::SortFlags)(uint)sort); };

Dir::SortFlags Dir::sorting() const
{ return (Dir::SortFlags)(uint)qdir.sorting(); };

void Dir::swap(QDir & other)
{ return qdir.swap(other); };



void DirAttached::addSearchPath(const QString & prefix, const QString & path)
{ return QDir::addSearchPath(prefix, path); };

QString DirAttached::cleanPath(const QString & path)
{ return QDir::cleanPath(path); };

Dir* DirAttached::current() // Return as Dir* instead of QDir
{ return new Dir(QDir::current()); };

QString DirAttached::currentPath()
{ return QDir::currentPath(); };

// QFileInfoList drives()

QString DirAttached::fromNativeSeparators(const QString & pathName)
{ return QDir::fromNativeSeparators(pathName); };

Dir* DirAttached::home() // Return as Dir* instead of QDir
{ return new Dir(QDir::home()); };

QString DirAttached::homePath()
{ return QDir::homePath(); };

bool DirAttached::isAbsolutePath(const QString & path)
{ return QDir::isAbsolutePath(path); };

bool DirAttached::isRelativePath(const QString & path)
{ return QDir::isRelativePath(path); };

bool DirAttached::match(const QString & filter, const QString & fileName)
{ return QDir::match(filter, fileName); };

bool DirAttached::match(const QStringList & filters, const QString & fileName)
{ return QDir::match(filters, fileName); };

Dir* DirAttached::root() // Return as Dir* instead of QDir
{ return new Dir(QDir::root()); };

QString DirAttached::rootPath()
{ return QDir::rootPath(); };

QStringList DirAttached::searchPaths(const QString & prefix)
{ return QDir::searchPaths(prefix); };

QString DirAttached::separator() // Return as QString instead of QChar
{ return QString(QDir::separator()); };

bool  DirAttached::setCurrent(const QString & path)
{ return QDir::setCurrent(path); };

void DirAttached::setSearchPaths(const QString & prefix, const QStringList & searchPaths)
{ return QDir::setSearchPaths(prefix, searchPaths); };

Dir* DirAttached::temp() // Return as Dir* instead of QDir
{ return new Dir(QDir::temp()); };

QString DirAttached::tempPath()
{ return QDir::tempPath(); };

QString DirAttached::toNativeSeparators(const QString & pathName)
{ return QDir::toNativeSeparators(pathName); };