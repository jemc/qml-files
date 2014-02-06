
#ifndef QML_FILES_FILE_H
#define QML_FILES_FILE_H

#include <qqml.h>
#include <QtCore/qobject.h>
#include <QtQml/5.2.0/QtQml/private/qtqmlglobal_p.h>


class wQFilePrivate;
class Q_QML_PRIVATE_EXPORT wQFile : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(wQFile)
    Q_INTERFACES(QQmlParserStatus)
    
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    
public:
    wQFile(QObject *parent=0);
    
protected:
    void classBegin();
    void componentComplete();
    
public slots:
    // bool    copy(const QString & newName);
    // bool    exists() const;
    // bool    link(const QString & linkName);
    // bool    open(FILE * fh, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle);
    // bool    open(int fd, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle);
    // bool    remove();
    // bool    rename(const QString & newName);
    void    setFileName(const QString & name);
    // QString symLinkTarget() const;
    
    QString fileName() const;
    // bool    open(OpenMode mode);
    // Permissions permissions() const;
    // bool    resize(qint64 sz);
    // bool    setPermissions(Permissions permissions);
    // qint64  size() const;
};


#endif
