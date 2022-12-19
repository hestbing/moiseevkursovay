#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dobavit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    okno = new dobavit(this);
        
    l = new QLabel(this);
    l->setText("Нажмите два раза на строку, чтобы удалить её");
    l->setGeometry(116,640,282,15);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./data.db");
    db.open();

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE AD(Название услуги,Специалист,Стоимость,Время)");

    model = new QSqlTableModel(this,db);
    model->setTable("AD");
    model->select();

    ui->t->setModel(model);
    ui->t->setGeometry(0,100,520,500);

     k = new QPushButton(this);
     k->setGeometry(195,40,150,40);
     k->setText("Добавить услугу");
     k->show();

//     k1 = new QPushButton(this);
//     k1->setGeometry(0,0,150,40);
//     k1->setText("Удалиить");
//     k1->show();

     connect(k,SIGNAL(clicked()),this,SLOT(slot1()));
     connect(ui->t,SIGNAL(doubleClicked(const QModelIndex )),this,SLOT(slot2()));
     connect(okno,&dobavit::signaldobavit,this,&MainWindow::slot3);
     connect(okno,&dobavit::signaldobavit1,this,&MainWindow::slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot1()
{
   okno->resize(830,125);
   okno->show();
   count=model->rowCount();
}

void MainWindow::slot2()
{
    model->removeRow(ui->t->currentIndex().row());
}


void MainWindow::slot()
{
    model->insertRow(model->rowCount());
    model->submitAll();
}
void MainWindow::slot3(QString a,QString b,QString c,QString d)
{
    model->setData(model->index(count,0),a);
    model->setData(model->index(count,1),b);
    model->setData(model->index(count,2),c.toInt());
    model->setData(model->index(count,3),d);
    model->submitAll();
    model->select();
    count++;
}
