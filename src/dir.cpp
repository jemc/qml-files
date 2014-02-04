
#include "dir.h"


QObject* Dir::qmlAttachedProperties(QObject* object)
{
    return new DirAttached(object);
}
