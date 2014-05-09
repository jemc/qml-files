
#ifndef QML_FILES_FILE_H
#define QML_FILES_FILE_H

#include <QtQml>
#include <QFile>


class wQFile : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString     fileName    READ fileName    WRITE setFileName)
    
    Q_PROPERTY(bool        exists         READ exists)
    Q_PROPERTY(QString     symLinkTarget  READ symLinkTarget)
    Q_PROPERTY(Permissions permissions    READ permissions)
    Q_PROPERTY(qint64      size           READ size)
    Q_PROPERTY(qint64      pos            READ pos)
    Q_PROPERTY(qint64      bytesAvailable READ bytesAvailable)
    Q_PROPERTY(bool        isOpen         READ isOpen)
    
    Q_PROPERTY(QString     md5            READ md5)
    
public:
    static QObject* qmlAttachedProperties(QObject* object);
    
    wQFile(QObject *parent=0);
    wQFile(const QString& path) { qfile.setFileName(path); };
    
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
    
private:
    QFile qfile;
    
protected:
    void classBegin();
    void componentComplete();
    
public slots:
    // bool    copy(const QString & newName);
    bool    exists() const;
    // bool    link(const QString & linkName);
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

    qint64  bytesAvailable() const;
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
    
    // Compute the MD5 hash of the file, and return it, as a hex string
    QString md5() {
        bool wasOpen = this->isOpen();
        this->open(OpenMode::ReadOnly);
        
        QCryptographicHash* hash = new QCryptographicHash(QCryptographicHash::Md5);
        hash->addData(&qfile);
        QString result = QString(hash->result().toHex());
        
        if(!wasOpen) this->close();
        delete hash;
        
        return result;
    }
    
signals:
    // void    aboutToClose()
    // void    bytesWritten(qint64 bytes)
    // void    readChannelFinished()
    // void    readyRead()
};


class wQFileAttached : public QObject
{
    Q_OBJECT
    
public slots:
    
    // Convenience constructor
    wQFile* _(QString path) {
        return new wQFile(path);
    };
    
public:
    wQFileAttached(QObject* attached)
    { m_attached = attached; };
    
private:
    QObject* m_attached = NULL;
};


QML_DECLARE_TYPEINFO(wQFile, QML_HAS_ATTACHED_PROPERTIES)


#endif
