
#ifndef QML_FILES_FILESYSTEMWATCHER_H
#define QML_FILES_FILESYSTEMWATCHER_H

#include <QtQml>
#include <QFileSystemWatcher>


class FileSystemWatcher : public QObject
{
    Q_OBJECT
    
public:
    static QObject* qmlAttachedProperties(QObject* object);
    
    FileSystemWatcher() { _init(); };
    
private:
    void _init()
    {
        QObject::connect(&qwatcher, &QFileSystemWatcher::directoryChanged,
            [=](const QString & path) { emit directoryChanged(path); });
        
        QObject::connect(&qwatcher, &QFileSystemWatcher::fileChanged,
            [=](const QString & path) { emit fileChanged(path); });
    }
    
private:
    QFileSystemWatcher qwatcher;
    
signals:
    void directoryChanged(const QString & path);
    void fileChanged(const QString & path);
    
public slots:
    bool addPath(const QString & path);
    QStringList addPaths(const QStringList & paths);
    QStringList directories();
    QStringList files();
    bool removePath(const QString & path);
    QStringList removePaths(const QStringList & paths);
};


#endif
