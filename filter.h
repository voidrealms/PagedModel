#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QThread>

class Filter : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit Filter(QObject *parent = nullptr);


    bool pageData();
    void setPageData(bool value);

    int pageSize();
    void setPageSize(int value);

    int pageCount();

    void filterPaged(QString pattern);

    int currentPage();
    void setCurrentPage(int value);


signals:
    void started() const;
    void finished() const;

public slots:
    void back();
    void next();


    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    bool pagedata;
    int pagesize;
    int currentpage;
    QString regxpattern;
    mutable int total_added;
    mutable int total_passed;
    mutable int total_processed;
    mutable int total_pages;
    int min;
    int max;

    void search();
    void calcRange();
    bool process(bool allowed, bool countonly, QString reason) const;

};

#endif // FILTER_H
