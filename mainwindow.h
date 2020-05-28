#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include "data.h"
#include "filter.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSearch_clicked();
    void on_btnBack_clicked();
    void on_btnNext_clicked();

    void on_actionCreate_Test_File_triggered();
    void started();
    void finished();

private:
    Ui::MainWindow *ui;
    QStandardItemModel model;
    Filter filter;

    void makeTestData();
    void loadFile(QString path);
};
#endif // MAINWINDOW_H
