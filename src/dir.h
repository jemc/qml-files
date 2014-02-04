
#ifndef QML_TETHERED_TETHERED_H
#define QML_TETHERED_TETHERED_H

#include <QtQml>


class Dir : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(uint value MEMBER m_value NOTIFY valueChanged)
    
signals:
    void valueChanged();
    
public:
    
public slots:
    
public:
    uint m_value = 8;
};

#endif
