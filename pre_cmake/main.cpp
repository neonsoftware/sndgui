#include "mainwindow.h"
#include "loaddialog.h"
#include "editdialog.h"
#include "style.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //qApp->setStyle(sndgui_style.style);
    //qApp->setPalette(sndgui_style.global_palette);
    //mSVGRendered->setStyleSheet("background-color: white; border:0px;");
    qApp->setStyleSheet("QSvgWidget{background-color: white; border:1px;}");

    MainWindow w;
    w.show();

    LoadDialog l;
    l.show();
    EditDialog e;
    e.show();

    return a.exec();
}
