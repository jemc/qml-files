
#ifndef QML_FILES_DIR_H
#define QML_FILES_DIR_H

#include <QtQml>


class Dir : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(uint value MEMBER m_value NOTIFY valueChanged)
    
signals:
    void valueChanged();
    
public:
    static QObject* getSingleton(QQmlEngine *engine, QJSEngine *scriptEngine);
    
public slots:
    
public:
    uint m_value = 8;
};


#endif
