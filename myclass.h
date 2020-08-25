#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QList>
#include <QRandomGenerator>
#include <QDataStream>
#include <QIODevice>
#include <QDebug>


class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

    void createRandom(int max);
    void toDevice(QIODevice *device);
    void fromDevice(QIODevice *device);
    void display();

signals:

private:
    QList<int> m_list;


};

#endif // MYCLASS_H
