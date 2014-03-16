
#include "file.h"


wQFile::wQFile(QObject *parent) { Q_UNUSED(parent); WQ_INIT_PRIV(QFile); }

void wQFile::classBegin() { }

void wQFile::componentComplete() { }


// bool    wQFile::copy(const QString & newName)

bool    wQFile::exists() const
{ WQ_PRIV(const QFile); return o->exists(); };

// bool    wQFile::link(const QString & linkName)

// bool    wQFile::open(FILE * fh, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle)

// bool    wQFile::open(int fd, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle)

// bool    wQFile::remove()

// bool    wQFile::rename(const QString & newName)

void    wQFile::setFileName(const QString & name)
{ WQ_PRIV(QFile); return o->setFileName(name); };

QString wQFile::symLinkTarget() const
{ WQ_PRIV(const QFile); return o->symLinkTarget(); };


QString wQFile::fileName() const
{ WQ_PRIV(const QFile); return o->fileName(); };

// bool    wQFile::open(OpenMode mode)

// Permissions wQFile::permissions() const

// bool    wQFile::resize(qint64 sz)

// bool    wQFile::setPermissions(Permissions permissions)

qint64  wQFile::size() const
{ WQ_PRIV(const QFile); return o->size(); };


// FileError   wQFile::error() const

// bool    wQFile::flush()

// int wQFile::handle() const

// uchar * wQFile::map(qint64 offset, qint64 size, MemoryMapFlags flags = NoOptions)

// bool    wQFile::unmap(uchar * address)

// void    wQFile::unsetError()



// bool    wQFile::atEnd() const

// void    wQFile::close()

// bool    wQFile::isSequential() const

// qint64  wQFile::pos() const

// bool    wQFile::seek(qint64 pos)



// qint64  wQFile::bytesAvailable() const

// qint64  wQFile::bytesToWrite() const

// bool    wQFile::canReadLine() const

// QString wQFile::errorString() const

// bool    wQFile::getChar(char * c)

// bool    wQFile::isOpen() const

// bool    wQFile::isReadable() const

// bool    wQFile::isTextModeEnabled() const

// bool    wQFile::isWritable() const

// OpenMode    wQFile::openMode() const

// qint64  wQFile::peek(char * data, qint64 maxSize)

// QByteArray  wQFile::peek(qint64 maxSize)

// bool    wQFile::putChar(char c)

// qint64  wQFile::read(char * data, qint64 maxSize)

// QByteArray  wQFile::read(qint64 maxSize)

// QByteArray  wQFile::readAll()

// qint64  wQFile::readLine(char * data, qint64 maxSize)

// QByteArray  wQFile::readLine(qint64 maxSize = 0)

// bool    wQFile::reset()

// bool    wQFile::seek(qint64 pos)

// void    wQFile::setTextModeEnabled(bool enabled)

// void    wQFile::ungetChar(char c)

// bool    wQFile::waitForBytesWritten(int msecs)

// bool    wQFile::waitForReadyRead(int msecs)

// qint64  wQFile::write(const char * data, qint64 maxSize)

// qint64  wQFile::write(const char * data)

// qint64  wQFile::write(const QByteArray & byteArray)
