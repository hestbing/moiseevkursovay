#include "dobavit.h"
#include "ui_dobavit.h"
#include "mainwindow.h"



dobavit::dobavit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dobavit)
{
    ui->setupUi(this);

    setWindowTitle("Добавить услугу");


    o = new QPushButton{this};
    o->show();
    o->setText("Добавить услугу");
    o->setGeometry(415,70,150,25);

    q=new QLabel(this);
    q->setText("Название услуги");
    q->setGeometry(20,10,150,15);

    box1 = new QComboBox(this);
    box1->setGeometry(0,30,200,25);
    box1->show();
    box1->addItem("Невролог");box1->addItem("Психиатор");box1->addItem("Хирургия");box1->addItem("Ревматология");box1->addItem("Урология");

    w=new QLabel(this);
    w->setText("Наименование специальста");
    w->setGeometry(230,10,200,15);

    line2 = new QLineEdit(this);
    line2->setGeometry(210,30,200,25);
    line2->show();
    line2->setText("Моисеев");

    e=new QLabel(this);
    e->setText("Cтоимость услуги(в рублях)");
    e->setGeometry(440,10,175,15);

    line3 = new QLineEdit(this);
    line3->setGeometry(420,30,200,25);
    line3->show();
    line3->setText("100");

    r=new QLabel(this);
    r->setText("Время оказание услуги");
    r->setGeometry(650,10,150,15);

    box = new QComboBox(this);
    box->setGeometry(630,30,200,25);
    box->show();
    box->addItem("12:00-12:30");box->addItem("12:30-13:00");box->addItem("13:00-13:30");box->addItem("13:30-14:00");box->addItem("14:00-14:30");
    box->addItem("14:30-15:00");box->addItem("15:00-15:30");box->addItem("15:30-16:00");box->addItem("16:00-16:30");box->addItem("16:30-17:00");

    connect(box1,SIGNAL(currentIndexChanged(int)),this,SLOT(slot1(int)));
    connect(o,SIGNAL(clicked()),this,SLOT(slot3()));
    connect(o,SIGNAL(clicked()),this,SLOT(slot2()));


}
dobavit::~dobavit()
{
    delete ui;
}


void dobavit::slot3()
{
    emit signaldobavit1();
}
void dobavit::slot2()
{
            emit signaldobavit(box1->currentText(),line2->text(),line3->text(),box->currentText());
}

void dobavit::slot1(int)
{
    if(box1->currentText()=="Невролог")
        {
            line2->setText("Моисеев");
            line3->setText("100");

        }
    if(box1->currentText()=="Психиатор")
        {
            line2->setText("Пишев");
            line3->setText("150");
        }
    if(box1->currentText()=="Хирургия")
        {
            line2->setText("Ботвинин");
            line3->setText("200");
        }
    if(box1->currentText()=="Ревматология")
        {
            line2->setText("Касаткин");
            line3->setText("250");
        }
    if(box1->currentText()=="Урология")
        {
            line2->setText("Иванов");
            line3->setText("300");
        }
}
