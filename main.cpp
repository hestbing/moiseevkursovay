#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(520,700);
    w.setWindowTitle("Список услуг");
    w.show();
    return a.exec();
}
