//#include "mainwindow.h"
#include "loaddialog.h"
#include "editdialog.h"
//#include "style.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoadDialog l;
    l.show();


    EditDialog e;
    e.show();
    
    return a.exec();
}
