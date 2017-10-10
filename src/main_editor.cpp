#include "editdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EditDialog e;
    e.show();
    
    return a.exec();
}
