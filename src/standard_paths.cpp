
#include "standard_paths.h"


QObject* StandardPaths::qmlAttachedProperties(QObject* object)
{
    return new StandardPathsAttached(object);
}


QString StandardPathsAttached::displayName(uint type)
{ return QStandardPaths::displayName((QStandardPaths::StandardLocation)type); }

QString StandardPathsAttached::findExecutable(const QString& executableName)
{ return QStandardPaths::findExecutable(executableName); }

void StandardPathsAttached::setTestModeEnabled(bool testMode)
{ QStandardPaths::setTestModeEnabled(testMode); }

QStringList StandardPathsAttached::standardLocations(uint type)
{ return QStandardPaths::standardLocations((QStandardPaths::StandardLocation)type); }

QString StandardPathsAttached::writableLocation(uint type)
{ return QStandardPaths::writableLocation((QStandardPaths::StandardLocation)type); }
