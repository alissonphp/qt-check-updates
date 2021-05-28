#include "mainwindow.h"
#include "checkupdate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    CheckUpdate c;
    //w.show();
    return a.exec();
}
