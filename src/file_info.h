
#ifndef QML_FILES_FILEINFO_H
#define QML_FILES_FILEINFO_H

#include <QtQml>
#include <QFileInfo>


class FileInfo : public QObject
{
    Q_OBJECT
    
public:
    static QObject* qmlAttachedProperties(QObject* object);
    
    FileInfo() { qfileinfo = QFileInfo(""); };
    FileInfo(const QFileInfo& info) { qfileinfo = QFileInfo(info); };
    
    QFileInfo qfileinfo;
    
public slots:
    // QDir absoluteDir()
    
    QString absoluteFilePath()
    { return qfileinfo.absoluteFilePath(); };
    
    QString absolutePath()
    { return qfileinfo.absolutePath(); };
    
    QString baseName()
    { return qfileinfo.baseName(); };
    
    QString bundleName()
    { return qfileinfo.bundleName(); };
    
    bool caching()
    { return qfileinfo.caching(); };
    
    QString canonicalFilePath()
    { return qfileinfo.canonicalFilePath(); };
    
    QString canonicalPath()
    { return qfileinfo.canonicalPath(); };
    
    QString completeBaseName()
    { return qfileinfo.completeBaseName(); };
    
    QString completeSuffix()
    { return qfileinfo.completeSuffix(); };
    
    // QDateTime created()
    
    // QDir dir()
    
    bool exists()
    { return qfileinfo.exists(); };
    
    QString fileName()
    { return qfileinfo.fileName(); };
    
    QString filePath()
    { return qfileinfo.filePath(); };
    
    QString group()
    { return qfileinfo.group(); };
    
    uint groupId()
    { return qfileinfo.groupId(); };
    
    bool isAbsolute()
    { return qfileinfo.isAbsolute(); };
    
    bool isBundle()
    { return qfileinfo.isBundle(); };
    
    bool isDir()
    { return qfileinfo.isDir(); };
    
    bool isExecutable()
    { return qfileinfo.isExecutable(); };
    
    bool isFile()
    { return qfileinfo.isFile(); };
    
    bool isHidden()
    { return qfileinfo.isHidden(); };
    
    bool isNativePath()
    { return qfileinfo.isNativePath(); };
    
    bool isReadable()
    { return qfileinfo.isReadable(); };
    
    bool isRelative()
    { return qfileinfo.isRelative(); };
    
    bool isRoot()
    { return qfileinfo.isRoot(); };
    
    bool isSymLink()
    { return qfileinfo.isSymLink(); };
    
    bool isWritable()
    { return qfileinfo.isWritable(); };
    
    // QDateTime lastModified()
    
    // QDateTime lastRead()
    
    bool makeAbsolute()
    { return qfileinfo.makeAbsolute(); };
    
    QString owner()
    { return qfileinfo.owner(); };
    
    uint ownerId()
    { return qfileinfo.ownerId(); };
    
    QString path()
    { return qfileinfo.path(); };
    
    // bool permission(QFile::Permissions permissions)
    
    // QFile::Permissions permissions()
    
    void refresh()
    { return qfileinfo.refresh(); };
    
    void setCaching(bool enable)
    { return qfileinfo.setCaching(enable); };
    
    void setFile(const QString & file)
    { return qfileinfo.setFile(file); };
    
    // void setFile(const QFile & file)
    
    // void setFile(const QDir & dir, const QString & file)
    
    qint64 size()
    { return qfileinfo.size(); };
    
    QString suffix()
    { return qfileinfo.suffix(); };
    
    // void swap(QFileInfo & other)
    
    QString symLinkTarget()
    { return qfileinfo.symLinkTarget(); };
    
};


class FileInfoAttached : public QObject
{
    Q_OBJECT
    
public slots:
    bool exists(const QString & file)
    { return QFileInfo::exists(file); };
    
public:
    FileInfoAttached(QObject* attached)
    { m_attached = attached; };
    
private:
    QObject* m_attached = NULL;
};


QML_DECLARE_TYPEINFO(FileInfo, QML_HAS_ATTACHED_PROPERTIES)

#endif
