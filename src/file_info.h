
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
    // QDir absoluteDir();
    QString absoluteFilePath();
    QString absolutePath();
    QString baseName();
    QString bundleName();
    bool caching();
    QString canonicalFilePath();
    QString canonicalPath();
    QString completeBaseName();
    QString completeSuffix();
    // QDateTime created();
    // QDir dir();
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
    // QDateTime lastModified();
    // QDateTime lastRead();
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
