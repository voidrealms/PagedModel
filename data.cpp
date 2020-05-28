#include "data.h"

Data::Data(QObject *parent) : QObject(parent)
{

}

bool Data::writeTest(QString path, int rows)
{
    //Write a lot of test data to a file


    QFile file(path);
    if(file.exists()) return true;
    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "could not create: " << path;
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    for(int i = 0; i < rows; i++)
    {
        QString data = QString::number(i);
        stream << data << "\r\n";

    }
    stream.flush();
    file.close();
    qDebug() << "Created: " << path;

    return true;
}

bool Data::loadTable(QString path, QStandardItemModel *model)
{
    //Load the file into the model
    model->clear();

    //Setup the model
    QStringList headers;
    headers.append("Item");

    model->setColumnCount(1);
    model->setHorizontalHeaderLabels(headers);


    //Fill the model with data
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "could not create: " << path;
        qCritical() << file.errorString();
        return false;
    }
    QTextStream stream(&file);

    while(!stream.atEnd()) {
        QString line = stream.readLine();
        model->appendRow(new QStandardItem(line));
    }
    file.close();
    qDebug() << "Loaded: " << path;
    qDebug() << "Model Row count: " << model->rowCount();
    return true;

}
