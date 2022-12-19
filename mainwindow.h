#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include "QLabel"
#include "QTableView"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlTableModel"
#include "dobavit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slot1();
    void slot2();

private:
    int count=0;
    QPushButton *k,*k1;
   // QTableView *t;
    Ui::MainWindow *ui;
    dobavit *okno;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QLabel *l;
    int row;
signals:
  void signal();

public slots:
   void slot();
   void slot3(QString a,QString b,QString c,QString d);
};

#endif // MAINWINDOW_H
