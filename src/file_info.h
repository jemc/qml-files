
#ifndef QML_FILES_FILEINFO_H
#define QML_FILES_FILEINFO_H

#include <QtQml>
#include <QFileInfo>


class FileInfo : public QObject
{
    Q_OBJECT
    
public:
    static QObject* qmlAttachedProperties(QObject* object);
    
    FileInfo() { qdir = QFileInfo(""); };
    FileInfo(const QFileInfo& dir) { qdir = QFileInfo(dir); };
    
    QFileInfo qdir;
    
public slots:
    
};


class FileInfoAttached : public QObject
{
    Q_OBJECT
    
public slots:
    
public:
    FileInfoAttached(QObject* attached)
    { m_attached = attached; };
    
private:
    QObject* m_attached = NULL;
};


QML_DECLARE_TYPEINFO(FileInfo, QML_HAS_ATTACHED_PROPERTIES)

#endif
