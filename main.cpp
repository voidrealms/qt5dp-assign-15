#include <QCoreApplication>

/*
 What
 Serialize an object with QDataStream

 Description
 We want an object to be stored on the disk or send to a QIODevice

 Why
 Many reasons...saving a file, sending the class across the web...so on

 Example
 IO Class

 */

#include <QBuffer>
#include <QDebug>
#include "myclass.h"

void makeData(QBuffer &data)
{
    qInfo() << "Making data";
    MyClass myclass;
    myclass.createRandom(3);
    myclass.display();
    myclass.toDevice(&data);
}

void loadData(QBuffer &data)
{
    qInfo() << "Loading data";
    MyClass myclass;
    data.seek(0);
    myclass.fromDevice(&data);
    myclass.display();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    makeData(buffer);
    loadData(buffer);
    buffer.close();

    return a.exec();
}
