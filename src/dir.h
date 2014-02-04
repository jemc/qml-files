
#ifndef QML_FILES_DIR_H
#define QML_FILES_DIR_H

#include <QtQml>


class Dir : public QObject
{
    Q_OBJECT
    
public:
    static QObject* getSingleton(QQmlEngine *engine, QJSEngine *scriptEngine);
    
public slots:
    void addSearchPath(const QString & prefix, const QString & path)
    { return QDir::addSearchPath(prefix, path); };
    
    QString cleanPath(const QString & path)
    { return QDir::cleanPath(path); };
    
    // QDir current()
    
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
    
};


#endif
