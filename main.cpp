#include "mainwindow.h"
#include "loaddialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();

    LoadDialog l;
    l.show();

    return a.exec();
}
