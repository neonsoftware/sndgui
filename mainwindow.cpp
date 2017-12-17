#include <string>
#include "mainwindow.h"
#include "loaddialog.h"
#include "ui_mainwindow.h"
#include "QtCore"
#include "QtGui"
#include "QtWidgets"
#include "sndwch.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoadDialog * ld = new LoadDialog(this);
    ld->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered(){

    QString configFile = QFileDialog::getOpenFileName();
    QMessageBox msgBox;
    msgBox.setText(QString("Config file is ") + configFile);
    msgBox.exec();
}

void MainWindow::on_actionAdd_triggered()
{
     ui->listWidget->addItems(QFileDialog::getOpenFileNames());
}

void MainWindow::on_actionRemove_triggered()
{
    /* for(auto item : ui->listWidget->selectedItems()){
        ui->listWidget->takeItem(ui->listWidget->row(item));

    } */

    const char *p1_ = "/opt/garage/sndwch/test/assets/a.svg";
    const char *p2_ = "/opt/garage/sndwch/test/assets/b.svg";
    const char *paths[2];
    paths[0] = p1_;
    paths[1] = p2_;
    int res = swc_merge(paths, 2, "./merged.svg");
    if (res != SWC_OK)
            QMessageBox::information(this, "result", "Error Merging.");

}

void MainWindow::on_actionRun_triggered()
{
    swc_cut2d_t a, b;
    //isCutEquivalent(&a, &b);

    size_t paths_present = ui->listWidget->count();
    char paths[2][1024] = {"", ""};
    for(size_t i = 0; i < paths_present; i++){
        std::string s = ui->listWidget->item(i)->text().toStdString();
        strncpy(paths[i], s.c_str(), strlen(s.c_str()));
        paths[i][strlen(s.c_str())] = '\0';
    }

    for(size_t i = 0; i < paths_present; i++){
        std::string s = paths[i];
        std::string a = s;
    }
    const char** c = (const char**)paths;

    const char *p1_ = "/opt/garage/sndwch/test/assets/a.svg";
    const char *p2_ = "/opt/garage/sndwch/test/assets/b.svg";
    const char *paths_[2];
    paths_[0] = p1_;
    paths_[1] = p2_;

    std::string d(c[0]);

    snd_err_t res = swc_merge(c, 2, "./merged.svg");
    if (res != SWC_OK)
        QMessageBox::information(this, "result", "Error Merging.");
    else
        QMessageBox::information(this, "result", "Ok !");
}
