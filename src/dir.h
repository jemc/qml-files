
#ifndef QML_FILES_DIR_H
#define QML_FILES_DIR_H

#include <QtQml>
#include <QDir>


class Dir : public QObject
{
    Q_OBJECT
    
public:
    static QObject* qmlAttachedProperties(QObject* object);
    
    Dir() { qdir = QDir(""); };
    Dir(const QDir& dir) { qdir = QDir(dir); };
    
    QDir qdir;
    
public slots:
    // QDir(const QDir & dir)
    
    // QDir(const QString & path = QString())
    
    // QDir(const QString & path, const QString & nameFilter, SortFlags sort = SortFlags( Name | IgnoreCase ), Filters filters = AllEntries)
    
    // ~QDir()
    
    QString absoluteFilePath(const QString & fileName)
    { return qdir.absoluteFilePath(fileName);};
    
    QString absolutePath()
    { return qdir.absolutePath(); };
    
    QString canonicalPath()
    { return qdir.canonicalPath(); };
    
    bool cd(const QString & dirName)
    { return qdir.cd(dirName);};
    
    bool cdUp()
    { return qdir.cdUp(); };
    
    uint count()
    { return qdir.count(); };
    
    QString dirName()
    { return qdir.dirName(); };
    
    // QFileInfoList   entryInfoList(const QStringList & nameFilters, Filters filters = NoFilter, SortFlags sort = NoSort)
    
    // QFileInfoList   entryInfoList(Filters filters = NoFilter, SortFlags sort = NoSort)
    
    // QStringList entryList(const QStringList & nameFilters, Filters filters = NoFilter, SortFlags sort = NoSort)
    
    // QStringList entryList(Filters filters = NoFilter, SortFlags sort = NoSort)
    
    bool exists(const QString & name)
    { return qdir.exists(name); };
    
    bool exists()
    { return qdir.exists(); };
    
    QString filePath(const QString & fileName)
    { return qdir.filePath(fileName);};
    
    // Filters filter()
    // { return qdir.filter(); };
    
    bool isAbsolute()
    { return qdir.isAbsolute(); };
    
    bool isReadable()
    { return qdir.isReadable(); };
    
    bool isRelative()
    { return qdir.isRelative(); };
    
    bool isRoot()
    { return qdir.isRoot(); };
    
    bool makeAbsolute()
    { return qdir.makeAbsolute(); };
    
    bool mkdir(const QString & dirName)
    { return qdir.mkdir(dirName);  };
    
    bool mkpath(const QString & dirPath)
    { return qdir.mkpath(dirPath); };
    
    QStringList nameFilters()
    { return qdir.nameFilters(); };
    
    QString path()
    { return qdir.path(); };
    
    void refresh()
    { return qdir.refresh(); };
    
    QString relativeFilePath(const QString & fileName)
    { return qdir.relativeFilePath(fileName);};
    
    bool remove(const QString & fileName)
    { return qdir.remove(fileName); };
    
    bool removeRecursively()
    { return qdir.removeRecursively(); };
    
    bool rename(const QString & oldName, const QString & newName)
    { return qdir.rename(oldName, newName); };
    
    bool rmdir(const QString & dirName)
    { return qdir.rmdir(dirName); };
    
    bool rmpath(const QString & dirPath)
    { return qdir.rmpath(dirPath); };
    
    // void    setFilter(Filters filters)
    
    void setNameFilters(const QStringList & nameFilters)
    { return qdir.setNameFilters(nameFilters);};
    
    void setPath(const QString & path)
    { return qdir.setPath(path);};
    
    // void    setSorting(SortFlags sort)
    
    // SortFlags   sorting()
    // { return qdir.sorting(); };
    
    void swap(QDir & other)
    { return qdir.swap(other);};
};


class DirAttached : public QObject
{
    Q_OBJECT
    
public slots:
    void addSearchPath(const QString & prefix, const QString & path)
    { return QDir::addSearchPath(prefix, path); };
    
    QString cleanPath(const QString & path)
    { return QDir::cleanPath(path); };
    
    Dir* current()
    { return new Dir(QDir::current()); };
    
    QString currentPath()
    { return QDir::currentPath(); };
    
    // QFileInfoList drives()
    
    QString fromNativeSeparators(const QString & pathName)
    { return QDir::fromNativeSeparators(pathName); };
    
    // QDir home()
    
    QString homePath()
    { return QDir::homePath(); };
    
    bool isAbsolutePath(const QString & path)
    { return QDir::isAbsolutePath(path); };
    
    bool isRelativePath(const QString & path)
    { return QDir::isRelativePath(path); };
    
    bool match(const QString & filter, const QString & fileName)
    { return QDir::match(filter, fileName); };
    
    bool match(const QStringList & filters, const QString & fileName)
    { return QDir::match(filters, fileName); };
    
    // QDir root()
    
    QString rootPath()
    { return QDir::rootPath(); };
    
    QStringList searchPaths(const QString & prefix)
    { return QDir::searchPaths(prefix); };
    
    QString separator() // QChar separator() // Convert to QString
    { return QString(QDir::separator()); };
    
    bool  setCurrent(const QString & path)
    { return QDir::setCurrent(path); };
    
    void setSearchPaths(const QString & prefix, const QStringList & searchPaths)
    { return QDir::setSearchPaths(prefix, searchPaths); };
    
    // QDir temp()
    
    QString tempPath()
    { return QDir::tempPath(); };
    
    QString toNativeSeparators(const QString & pathName)
    { return QDir::toNativeSeparators(pathName); };
    
public:
    DirAttached(QObject* attached)
    { m_attached = attached; };
    
private:
    QObject* m_attached = NULL;
};


QML_DECLARE_TYPEINFO(Dir, QML_HAS_ATTACHED_PROPERTIES)

#endif
