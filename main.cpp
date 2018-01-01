#include "mainwindow.h"
#include "loaddialog.h"
#include "editdialog.h"
#include "style.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qApp->setStyle(sndgui_style.style);
    qApp->setPalette(sndgui_style.global_palette);
    //qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    MainWindow w;
    w.show();

    LoadDialog l;
    l.show();
    EditDialog e;
    e.show();

    return a.exec();
}
