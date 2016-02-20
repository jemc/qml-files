
#include <QQmlExtensionPlugin>
#include <qqml.h>


#include "file_info.h"
#include "dir.h"
#include "file.h"
#include "file_system_watcher.h"
#include "standard_paths.h"


class QmlFilesPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri)
    {
        qmlRegisterType<FileInfo>(uri, 1, 0, "FileInfo");
        qmlRegisterType<FileInfoAttached>();
        qmlRegisterType<Dir>(uri, 1, 0, "Dir");
        qmlRegisterType<DirAttached>();
        qmlRegisterType<StandardPaths>(uri, 1, 0, "StandardPaths");
        qmlRegisterType<StandardPathsAttached>();
        qmlRegisterType<FileSystemWatcher>(uri, 1, 0, "FileSystemWatcher");
        
        qmlRegisterType<wQFile>(uri, 1, 0, "File");
    };
};
