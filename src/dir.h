
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
    
private:
    QDir qdir;
    
public slots:
    QString absoluteFilePath(const QString & fileName);
    QString absolutePath();
    QString canonicalPath();
    bool cd(const QString & dirName);
    bool cdUp();
    uint count();
    QString dirName();
    // QFileInfoList entryInfoList(const QStringList & nameFilters, Filters filters = NoFilter, SortFlags sort = NoSort);
    // QFileInfoList entryInfoList(Filters filters = NoFilter, SortFlags sort = NoSort);
    // QStringList entryList(const QStringList & nameFilters, Filters filters = NoFilter, SortFlags sort = NoSort);
    // QStringList entryList(Filters filters = NoFilter, SortFlags sort = NoSort);
    bool exists(const QString & name);
    bool exists();
    QString filePath(const QString & fileName);
    // Filters filter();
    bool isAbsolute();
    bool isReadable();
    bool isRelative();
    bool isRoot();
    bool makeAbsolute();
    bool mkdir(const QString & dirName);
    bool mkpath(const QString & dirPath);
    QStringList nameFilters();
    QString path();
    void refresh();
    QString relativeFilePath(const QString & fileName);
    bool remove(const QString & fileName);
    bool removeRecursively();
    bool rename(const QString & oldName, const QString & newName);
    bool rmdir(const QString & dirName);
    bool rmpath(const QString & dirPath);
    // void setFilter(Filters filters);
    void setNameFilters(const QStringList & nameFilters);
    void setPath(const QString & path);
    // void setSorting(SortFlags sort);
    // SortFlags sorting();
    void swap(QDir & other);
};


class DirAttached : public QObject
{
    Q_OBJECT
    
public slots:
    void addSearchPath(const QString & prefix, const QString & path);
    QString cleanPath(const QString & path);
    Dir* current();
    QString currentPath();
    // QFileInfoList drives();
    QString fromNativeSeparators(const QString & pathName);
    Dir* home();
    QString homePath();
    bool isAbsolutePath(const QString & path);
    bool isRelativePath(const QString & path);
    bool match(const QString & filter, const QString & fileName);
    bool match(const QStringList & filters, const QString & fileName);
    Dir* root();
    QString rootPath();
    QStringList searchPaths(const QString & prefix);
    QString separator();
    bool  setCurrent(const QString & path);
    void setSearchPaths(const QString & prefix, const QStringList & searchPaths);
    Dir* temp();
    QString tempPath();
    QString toNativeSeparators(const QString & pathName);
    
public:
    DirAttached(QObject* attached)
    { m_attached = attached; };
    
private:
    QObject* m_attached = NULL;
};


QML_DECLARE_TYPEINFO(Dir, QML_HAS_ATTACHED_PROPERTIES)

#endif
