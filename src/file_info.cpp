
#include "file_info.h"


QObject* FileInfo::qmlAttachedProperties(QObject* object)
{
    return new FileInfoAttached(object);
}


// QDir FileInfo::absoluteDir()

QString FileInfo::absoluteFilePath()
{ return qfileinfo.absoluteFilePath(); };

QString FileInfo::absolutePath()
{ return qfileinfo.absolutePath(); };

QString FileInfo::baseName()
{ return qfileinfo.baseName(); };

QString FileInfo::bundleName()
{ return qfileinfo.bundleName(); };

bool FileInfo::caching()
{ return qfileinfo.caching(); };

QString FileInfo::canonicalFilePath()
{ return qfileinfo.canonicalFilePath(); };

QString FileInfo::canonicalPath()
{ return qfileinfo.canonicalPath(); };

QString FileInfo::completeBaseName()
{ return qfileinfo.completeBaseName(); };

QString FileInfo::completeSuffix()
{ return qfileinfo.completeSuffix(); };

// QDateTime FileInfo::created()

// QDir FileInfo::dir()

bool FileInfo::exists()
{ return qfileinfo.exists(); };

QString FileInfo::fileName()
{ return qfileinfo.fileName(); };

QString FileInfo::filePath()
{ return qfileinfo.filePath(); };

QString FileInfo::group()
{ return qfileinfo.group(); };

uint FileInfo::groupId()
{ return qfileinfo.groupId(); };

bool FileInfo::isAbsolute()
{ return qfileinfo.isAbsolute(); };

bool FileInfo::isBundle()
{ return qfileinfo.isBundle(); };

bool FileInfo::isDir()
{ return qfileinfo.isDir(); };

bool FileInfo::isExecutable()
{ return qfileinfo.isExecutable(); };

bool FileInfo::isFile()
{ return qfileinfo.isFile(); };

bool FileInfo::isHidden()
{ return qfileinfo.isHidden(); };

bool FileInfo::isNativePath()
{ return qfileinfo.isNativePath(); };

bool FileInfo::isReadable()
{ return qfileinfo.isReadable(); };

bool FileInfo::isRelative()
{ return qfileinfo.isRelative(); };

bool FileInfo::isRoot()
{ return qfileinfo.isRoot(); };

bool FileInfo::isSymLink()
{ return qfileinfo.isSymLink(); };

bool FileInfo::isWritable()
{ return qfileinfo.isWritable(); };

// QDateTime FileInfo::lastModified()

// QDateTime FileInfo::lastRead()

bool FileInfo::makeAbsolute()
{ return qfileinfo.makeAbsolute(); };

QString FileInfo::owner()
{ return qfileinfo.owner(); };

uint FileInfo::ownerId()
{ return qfileinfo.ownerId(); };

QString FileInfo::path()
{ return qfileinfo.path(); };

// bool FileInfo::permission(QFile::Permissions permissions)

// QFile::Permissions FileInfo::permissions()

void FileInfo::refresh()
{ return qfileinfo.refresh(); };

void FileInfo::setCaching(bool enable)
{ return qfileinfo.setCaching(enable); };

void FileInfo::setFile(const QString & file)
{ return qfileinfo.setFile(file); };

// void FileInfo::setFile(const QFile & file)

// void FileInfo::setFile(const QDir & dir, const QString & file)

qint64 FileInfo::size()
{ return qfileinfo.size(); };

QString FileInfo::suffix()
{ return qfileinfo.suffix(); };

// void FileInfo::swap(QFileInfo & other)

QString FileInfo::symLinkTarget()
{ return qfileinfo.symLinkTarget(); };



bool FileInfoAttached::exists(const QString & file)
{ return QFileInfo::exists(file); };
