
#ifndef QML_FILES_FILEINFO_H
#define QML_FILES_FILEINFO_H

#include <QtQml>
#include <QFileInfo>

#include "dir.h"


class FileInfo : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(Dir*               absoluteDir       READ absoluteDir)
    Q_PROPERTY(QString            absoluteFilePath  READ absoluteFilePath)
    Q_PROPERTY(QString            absolutePath      READ absolutePath)
    Q_PROPERTY(QString            baseName          READ baseName)
    Q_PROPERTY(QString            bundleName        READ bundleName)
    Q_PROPERTY(bool               caching           READ caching)
    Q_PROPERTY(QString            canonicalFilePath READ canonicalFilePath)
    Q_PROPERTY(QString            canonicalPath     READ canonicalPath)
    Q_PROPERTY(QString            completeBaseName  READ completeBaseName)
    Q_PROPERTY(QString            completeSuffix    READ completeSuffix)
    Q_PROPERTY(QDateTime          created           READ created)
    Q_PROPERTY(Dir*               dir               READ dir)
    Q_PROPERTY(bool               exists            READ exists)
    Q_PROPERTY(QString            fileName          READ fileName)
    Q_PROPERTY(QString            filePath          READ filePath)
    Q_PROPERTY(QString            group             READ group)
    Q_PROPERTY(uint               groupId           READ groupId)
    Q_PROPERTY(bool               isAbsolute        READ isAbsolute)
    Q_PROPERTY(bool               isBundle          READ isBundle)
    Q_PROPERTY(bool               isDir             READ isDir)
    Q_PROPERTY(bool               isExecutable      READ isExecutable)
    Q_PROPERTY(bool               isFile            READ isFile)
    Q_PROPERTY(bool               isHidden          READ isHidden)
    Q_PROPERTY(bool               isNativePath      READ isNativePath)
    Q_PROPERTY(bool               isReadable        READ isReadable)
    Q_PROPERTY(bool               isRelative        READ isRelative)
    Q_PROPERTY(bool               isRoot            READ isRoot)
    Q_PROPERTY(bool               isSymLink         READ isSymLink)
    Q_PROPERTY(bool               isWritable        READ isWritable)
    Q_PROPERTY(QDateTime          lastModified      READ lastModified)
    Q_PROPERTY(QDateTime          lastRead          READ lastRead)
    Q_PROPERTY(QString            owner             READ owner)
    Q_PROPERTY(uint               ownerId           READ ownerId)
    Q_PROPERTY(QString            path              READ path)
    // Q_PROPERTY(QFile::Permissions permissions       READ permissions)
    Q_PROPERTY(qint64             size              READ size)
    Q_PROPERTY(QString            suffix            READ suffix)
    Q_PROPERTY(QString            symLinkTarget     READ symLinkTarget)
    
public:
    static QObject* qmlAttachedProperties(QObject* object);
    
    FileInfo() { qfileinfo = QFileInfo(""); };
    FileInfo(const QFileInfo& info) { qfileinfo = QFileInfo(info); };
    
private:
    QFileInfo qfileinfo;
    
public slots:
    Dir* absoluteDir();
    QString absoluteFilePath();
    QString absolutePath();
    QString baseName();
    QString bundleName();
    bool caching();
    QString canonicalFilePath();
    QString canonicalPath();
    QString completeBaseName();
    QString completeSuffix();
    QDateTime created();
    Dir* dir();
    bool exists();
    QString fileName();
    QString filePath();
    QString group();
    uint groupId();
    bool isAbsolute();
    bool isBundle();
    bool isDir();
    bool isExecutable();
    bool isFile();
    bool isHidden();
    bool isNativePath();
    bool isReadable();
    bool isRelative();
    bool isRoot();
    bool isSymLink();
    bool isWritable();
    QDateTime lastModified();
    QDateTime lastRead();
    bool makeAbsolute();
    QString owner();
    uint ownerId();
    QString path();
    // bool permission(QFile::Permissions permissions);
    // QFile::Permissions permissions();
    void refresh();
    void setCaching(bool enable);
    void setFile(const QString & file);
    // void setFile(const QFile & file);
    // void setFile(const QDir & dir, const QString & file);
    qint64 size();
    QString suffix();
    // void swap(QFileInfo & other);
    QString symLinkTarget();
};


class FileInfoAttached : public QObject
{
    Q_OBJECT
    
public slots:
    bool exists(const QString & file);
    
    // Convenience constructor
    FileInfo* _(QString path) { return new FileInfo(QFileInfo(path)); };
    
public:
    FileInfoAttached(QObject* attached)
    { m_attached = attached; };
    
private:
    QObject* m_attached = NULL;
};


QML_DECLARE_TYPEINFO(FileInfo, QML_HAS_ATTACHED_PROPERTIES)

#endif
