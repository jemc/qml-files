
#include "file_info.h"


QObject* FileInfo::qmlAttachedProperties(QObject* object)
{
    return new FileInfoAttached(object);
}
