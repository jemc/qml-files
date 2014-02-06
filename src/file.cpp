
#include <QFile>
#include <QtCore/5.2.0/QtCore/private/qobject_p.h>

#include "file.h"


class wQFilePrivate : public QObjectPrivate, public QFile
{
    Q_DECLARE_PUBLIC(wQFile)
};


wQFile::wQFile(QObject *parent) : QObject(*(new wQFilePrivate), parent) { }

void wQFile::classBegin() { }

void wQFile::componentComplete() { }


// bool    copy(const QString & newName)

// bool    exists() const

// bool    link(const QString & linkName)

// bool    open(FILE * fh, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle)

// bool    open(int fd, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle)

// bool    remove()

// bool    rename(const QString & newName)

void    wQFile::setFileName(const QString & name)
{ Q_D(wQFile); return d->setFileName(name); };

// QString symLinkTarget() const


QString wQFile::fileName() const
{ Q_D(const wQFile); return d->fileName(); };

// virtual bool    open(OpenMode mode)

// virtual Permissions permissions() const

// virtual bool    resize(qint64 sz)

// virtual bool    setPermissions(Permissions permissions)

// virtual qint64  size() const

