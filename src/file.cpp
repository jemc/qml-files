
#include "file.h"


wQFile::wQFile(QObject *parent) { Q_UNUSED(parent); }

void wQFile::classBegin() { }

void wQFile::componentComplete() { }


///
// Public Functions


// bool    wQFile::copy(const QString & newName)

bool    wQFile::exists() const
{ return qfile.exists(); };

// bool    wQFile::link(const QString & linkName)

// bool    wQFile::open(FILE * fh, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle)

// bool    wQFile::open(int fd, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle)

// bool    wQFile::remove()

// bool    wQFile::rename(const QString & newName)

void    wQFile::setFileName(const QString & name)
{ return qfile.setFileName(name); };

QString wQFile::symLinkTarget() const
{ return qfile.symLinkTarget(); };


///
// Reimplemented Public Functions


QString wQFile::fileName() const
{ return qfile.fileName(); };

bool    wQFile::open(OpenMode mode)
{ return qfile.open((QIODevice::OpenMode)mode); };

wQFile::Permissions wQFile::permissions() const
{ return (wQFile::Permissions)(int)qfile.permissions(); };

bool    wQFile::resize(qint64 sz)
{ return qfile.resize(sz); };

// bool    wQFile::setPermissions(wQFile::Permissions permissions)
// { return qfile.setPermissions((QFileDevice::Permissions)(int)permissions); };

qint64  wQFile::size() const
{ return qfile.size(); };


///
// public functions inherited from QFileDevice


// FileError   wQFile::error() const

// bool    wQFile::flush()

// int wQFile::handle() const

// uchar * wQFile::map(qint64 offset, qint64 size, MemoryMapFlags flags = NoOptions)

// bool    wQFile::unmap(uchar * address)

// void    wQFile::unsetError()


///
// reimplemented public functions inherited from QFileDevice


// bool    wQFile::atEnd() const

void    wQFile::close()
{ return qfile.close(); };

// bool    wQFile::isSequential() const

qint64  wQFile::pos() const
{ return qfile.pos(); };

bool    wQFile::seek(qint64 pos)
{ return qfile.seek(pos); };


///
// public functions inherited from QIODevice


qint64  wQFile::bytesAvailable() const
{ return qfile.bytesAvailable(); };

// qint64  wQFile::bytesToWrite() const

// bool    wQFile::canReadLine() const

// QString wQFile::errorString() const

// bool    wQFile::getChar(char * c)

bool    wQFile::isOpen() const
{ return qfile.isOpen(); };

// bool    wQFile::isReadable() const

// bool    wQFile::isTextModeEnabled() const

// bool    wQFile::isWritable() const

// OpenMode    wQFile::openMode() const

#define LATIN1_CHARS \
" !\"#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

QString  wQFile::peek(qint64 maxSize)
{ return QString::fromLatin1(qfile.peek(maxSize).toPercentEncoding(LATIN1_CHARS)); };

// bool    wQFile::putChar(char c)

QString  wQFile::read(qint64 maxSize)
{ return QString::fromLatin1(qfile.read(maxSize).toPercentEncoding(LATIN1_CHARS)); };

QString  wQFile::readAll()
{ return QString::fromLatin1(qfile.readAll().toPercentEncoding(LATIN1_CHARS)); };

QString  wQFile::readLine(qint64 maxSize)
{ if(maxSize > 0) maxSize++; // Add extra char for the null byte appended
  return QString::fromLatin1(qfile.readLine(maxSize).toPercentEncoding(LATIN1_CHARS)); };


bool    wQFile::reset()
{ return qfile.reset(); };

// void    wQFile::setTextModeEnabled(bool enabled)

// void    wQFile::ungetChar(char c)

// bool    wQFile::waitForBytesWritten(int msecs)

// bool    wQFile::waitForReadyRead(int msecs)

qint64  wQFile::write(const QString & string)
{ return qfile.write(QByteArray::fromPercentEncoding(string.toLatin1())); };
