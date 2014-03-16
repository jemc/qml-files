
#ifndef QML_FILES_FILE_H
#define QML_FILES_FILE_H

#include <QtQml>
#include <QFile>

#include "wq_priv.h"


class wQFile : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    WQ_DECL_PRIV(QFile)
    Q_INTERFACES(QQmlParserStatus)
    
    Q_PROPERTY(QString     fileName    READ fileName    WRITE setFileName)
    Q_PROPERTY(Permissions permissions READ permissions)
    
    Q_PROPERTY(bool    exists        READ exists)
    Q_PROPERTY(QString symLinkTarget READ symLinkTarget)
    Q_PROPERTY(qint64  size          READ size)
    Q_PROPERTY(qint64  pos           READ pos)
    
public:
    wQFile(QObject *parent=0);
    
    enum OpenMode {
        NotOpen    = QIODevice::NotOpen,
        ReadOnly   = QIODevice::ReadOnly,
        WriteOnly  = QIODevice::WriteOnly,
        ReadWrite  = QIODevice::ReadWrite,
        Append     = QIODevice::Append,
        Truncate   = QIODevice::Truncate,
        Text       = QIODevice::Text,
        Unbuffered = QIODevice::Unbuffered,
    };
    Q_ENUMS(OpenMode)
    
    enum Permissions {
        ReadOwner  = QFileDevice::ReadOwner,
        WriteOwner = QFileDevice::WriteOwner,
        ExeOwner   = QFileDevice::ExeOwner,
        ReadUser   = QFileDevice::ReadUser,
        WriteUser  = QFileDevice::WriteUser,
        ExeUser    = QFileDevice::ExeUser,
        ReadGroup  = QFileDevice::ReadGroup,
        WriteGroup = QFileDevice::WriteGroup,
        ExeGroup   = QFileDevice::ExeGroup,
        ReadOther  = QFileDevice::ReadOther,
        WriteOther = QFileDevice::WriteOther,
        ExeOther   = QFileDevice::ExeOther,
    };
    Q_ENUMS(Permissions)
    
    
protected:
    void classBegin();
    void componentComplete();
    
public slots:
    // bool    copy(const QString & newName);
    bool    exists() const;
    // bool    link(const QString & linkName);
    // bool    open(FILE * fh, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle);
    // bool    open(int fd, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle);
    // bool    remove();
    // bool    rename(const QString & newName);
    void    setFileName(const QString & name);
    QString symLinkTarget() const;
    
    QString fileName() const;
    bool    open(OpenMode mode);
    Permissions permissions() const;
    bool    resize(qint64 sz);
    // bool    setPermissions(Permissions permissions);
    qint64  size() const;
    
    // FileError   error() const
    // bool    flush()
    // int handle() const
    // uchar * map(qint64 offset, qint64 size, MemoryMapFlags flags = NoOptions)
    // bool    unmap(uchar * address)
    // void    unsetError()
    
    // bool    atEnd() const
    void    close();
    // bool    isSequential() const
    qint64  pos() const;
    bool    seek(qint64 pos);

    // qint64  bytesAvailable() const
    // qint64  bytesToWrite() const
    // bool    canReadLine() const
    // QString errorString() const
    // bool    getChar(char * c)
    bool    isOpen() const;
    // bool    isReadable() const
    // bool    isTextModeEnabled() const
    // bool    isWritable() const
    // OpenMode    openMode() const
    QString  peek(qint64 maxSize);
    // bool    putChar(char c)
    QString  read(qint64 maxSize);
    QString  readAll();
    QString  readLine(qint64 maxSize = 0);
    bool    reset();
    // void    setTextModeEnabled(bool enabled)
    // void    ungetChar(char c)
    // bool    waitForBytesWritten(int msecs)
    // bool    waitForReadyRead(int msecs)
    qint64  write(const QString & string);
    
signals:
    // void    aboutToClose()
    // void    bytesWritten(qint64 bytes)
    // void    readChannelFinished()
    // void    readyRead()
};


#endif
