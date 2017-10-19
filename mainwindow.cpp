#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtCore"
#include "QtWidgets"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_triggered()
{
     ui->listWidget->addItems(QFileDialog::getOpenFileNames());
}

void MainWindow::on_actionRemove_triggered()
{
    for(auto item : ui->listWidget->selectedItems()){
        ui->listWidget->takeItem(ui->listWidget->row(item));

    }
}

void MainWindow::on_actionRun_triggered()
{

}
