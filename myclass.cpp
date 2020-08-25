#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{
    Q_UNUSED(parent);
}

void MyClass::createRandom(int max)
{
    for(int i = 0; i < max; i++)
    {
        m_list.append(QRandomGenerator::global()->bounded(1000));
    }
}

void MyClass::toDevice(QIODevice *device)
{
    if(!device) return;
    if(!device->isWritable()) return;

    QDataStream stream(device);
    stream.setVersion(QDataStream::Qt_5_12);
    foreach(int value, m_list)
    {
        stream << value;
    }
}

void MyClass::fromDevice(QIODevice *device)
{
    if(!device) return;
    if(!device->isReadable()) return;

    QDataStream stream(device);
    stream.setVersion(QDataStream::Qt_5_12);
    while (!stream.atEnd())
    {
        int value;
        stream >> value;
        m_list.append(value);
    }
}

void MyClass::display()
{
    foreach(int value, m_list)
    {
        qInfo() << value;
    }
}
