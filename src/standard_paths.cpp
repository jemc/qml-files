
#include "standard_paths.h"


QObject* StandardPaths::qmlAttachedProperties(QObject* object)
{
    return new StandardPathsAttached(object);
}


QString StandardPathsAttached::writableLocation(uint type)
{ return QStandardPaths::writableLocation((QStandardPaths::StandardLocation)type); }
