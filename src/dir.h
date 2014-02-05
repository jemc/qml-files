
#ifndef QML_FILES_DIR_H
#define QML_FILES_DIR_H

#include <QtQml>
#include <QDir>


class Dir : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString     path          READ path           WRITE setPath)
    Q_PROPERTY(QStringList nameFilters   READ nameFilters    WRITE setNameFilters)
    Q_PROPERTY(QString     absolutePath  READ absolutePath)
    Q_PROPERTY(QString     canonicalPath READ canonicalPath)
    Q_PROPERTY(uint        count         READ count)
    Q_PROPERTY(QString     dirName       READ dirName)
    Q_PROPERTY(bool        exists        READ exists)
    // Q_PROPERTY(Filters     filter        READ filter)
    Q_PROPERTY(bool        isAbsolute    READ isAbsolute)
    Q_PROPERTY(bool        isReadable    READ isReadable)
    Q_PROPERTY(bool        isRelative    READ isRelative)
    Q_PROPERTY(bool        isRoot        READ isRoot)
    // Q_PROPERTY(SortFlags   sorting       READ sorting)
    
public:
    static QObject* qmlAttachedProperties(QObject* object);
    
    Dir() { qdir = QDir(""); };
    Dir(const QDir& dir) { qdir = QDir(dir); };
    
private:
    QDir qdir;
    
public slots:
    QString absoluteFilePath(const QString & fileName) const;
    QString absolutePath() const;
    QString canonicalPath() const;
    bool cd(const QString & dirName);
    bool cdUp();
    uint count() const;
    QString dirName() const;
    // QFileInfoList entryInfoList(const QStringList & nameFilters, Filters filters = NoFilter, SortFlags sort = NoSort) const;
    // QFileInfoList entryInfoList(Filters filters = NoFilter, SortFlags sort = NoSort) const;
    // QStringList entryList(const QStringList & nameFilters, Filters filters = NoFilter, SortFlags sort = NoSort) const;
    // QStringList entryList(Filters filters = NoFilter, SortFlags sort = NoSort) const;
    bool exists(const QString & name) const;
    bool exists() const;
    QString filePath(const QString & fileName) const;
    // Filters filter() const;
    bool isAbsolute() const;
    bool isReadable() const;
    bool isRelative() const;
    bool isRoot() const;
    bool makeAbsolute();
    bool mkdir(const QString & dirName) const;
    bool mkpath(const QString & dirPath) const;
    QStringList nameFilters() const;
    QString path() const;
    void refresh() const;
    QString relativeFilePath(const QString & fileName) const;
    bool remove(const QString & fileName);
    bool removeRecursively();
    bool rename(const QString & oldName, const QString & newName);
    bool rmdir(const QString & dirName) const;
    bool rmpath(const QString & dirPath) const;
    // void setFilter(Filters filters);
    void setNameFilters(const QStringList & nameFilters);
    void setPath(const QString & path);
    // void setSorting(SortFlags sort);
    // SortFlags sorting() const;
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
