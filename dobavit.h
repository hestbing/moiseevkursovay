#ifndef DOBAVIT_H
#define DOBAVIT_H

#include <QDialog>
#include "QLineEdit"
#include "QComboBox"
#include "QLabel"
#include "QPushButton"
#include "QTableWidget"

namespace Ui {
class dobavit;
}

class dobavit : public QDialog
{
    Q_OBJECT
public:
    explicit dobavit(QWidget *parent = 0);
    ~dobavit();


private slots:
    void slot1(int);
    void slot2();
    void slot3();

signals:
    void signaldobavit1();
    void signaldobavit(QString,QString,QString,QString);
private:
    Ui::dobavit *ui;
    QLineEdit *line2,*line3;
    QComboBox *box,*box1;
    QLabel *q,*w,*e,*r;
    QPushButton *o;
};

#endif // DOBAVIT_H
