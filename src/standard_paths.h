
#ifndef QML_FILES_STANDARD_PATHS_H
#define QML_FILES_STANDARD_PATHS_H

#include <QtQml>
#include <QStandardPaths>


class StandardPaths : public QObject
{
    Q_OBJECT
    
public:
    
    enum StandardLocation {
        DesktopLocation       = QStandardPaths::DesktopLocation,
        DocumentsLocation     = QStandardPaths::DocumentsLocation,
        FontsLocation         = QStandardPaths::FontsLocation,
        ApplicationsLocation  = QStandardPaths::ApplicationsLocation,
        MusicLocation         = QStandardPaths::MusicLocation,
        MoviesLocation        = QStandardPaths::MoviesLocation,
        PicturesLocation      = QStandardPaths::PicturesLocation,
        TempLocation          = QStandardPaths::TempLocation,
        HomeLocation          = QStandardPaths::HomeLocation,
        DataLocation          = QStandardPaths::DataLocation,
        CacheLocation         = QStandardPaths::CacheLocation,
        GenericCacheLocation  = QStandardPaths::GenericCacheLocation,
        GenericDataLocation   = QStandardPaths::GenericDataLocation,
        RuntimeLocation       = QStandardPaths::RuntimeLocation,
        ConfigLocation        = QStandardPaths::ConfigLocation,
        GenericConfigLocation = QStandardPaths::GenericConfigLocation,
        DownloadLocation      = QStandardPaths::DownloadLocation,
    };
    Q_ENUMS(StandardLocation)
    
    static QObject* qmlAttachedProperties(QObject* object);
};


class StandardPathsAttached : public QObject
{
    Q_OBJECT
    
public:
    StandardPathsAttached(QObject* attached)
    { m_attached = attached; };
    
private:
    QObject* m_attached = NULL;
    
public slots:
    void setTestModeEnabled(bool testMode);
    QStringList standardLocations(uint type);
    QString writableLocation(uint type);
};


QML_DECLARE_TYPEINFO(StandardPaths, QML_HAS_ATTACHED_PROPERTIES)

#endif
