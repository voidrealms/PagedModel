#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QStandardItemModel>

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject *parent = nullptr);

    bool writeTest(QString path, int rows);
    bool loadTable(QString path, QStandardItemModel *model);

signals:

};

#endif // DATA_H
