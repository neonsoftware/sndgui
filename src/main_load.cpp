#include "loaddialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoadDialog l;
    l.show();

    return a.exec();
}
