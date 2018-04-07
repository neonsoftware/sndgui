#include "FileSelectorWidget.h"
#include <QDebug>

FileSelectorWidget::FileSelectorWidget(QWidget *parent) : QWidget(parent),
    mFilesList(new QListWidget),
    mFlVl(new QVBoxLayout),
    mFlHl(new QHBoxLayout),
    mButtonAdd(new QToolButton),
    mButtonRemove(new QToolButton)
{
    // File List
    mFilesList->horizontalScrollBar()->setEnabled(false);
    mFilesList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //qDebug() << "min" << mFlVl->sizeConstraint().;

    mButtonAdd->setText("+");
    mButtonRemove->setText("-");

    QWidget *mFlW = new QWidget;
    mFlW->setAutoFillBackground(true);
    //mFlW->setFixedWidth(00);
    mFlHl->setContentsMargins(3,3,3,3);
    mFlHl->setSpacing(3);
    mFlHl->addWidget(mButtonAdd);
    mFlHl->addWidget(mButtonRemove);
    mFlHl->addStretch();
    mFlW->setLayout(mFlHl);

    mFlVl->addWidget(mFilesList);
    //mFlVl->SetFixedSize(QSize(100,300));
    mFlVl->addWidget(mFlW);
    mFlVl->setContentsMargins(0,0,0,0);
    mFlVl->setSpacing(0);

    mFilesList->setStyleSheet("border:0px;");

    this->setContentsMargins(0,0,0,0);
    this->setLayout(mFlVl);

    QObject::connect(mButtonAdd, &QToolButton::clicked,
                     this, &FileSelectorWidget::addFile);
    QObject::connect(mButtonRemove, &QToolButton::clicked,
                     this, &FileSelectorWidget::removeFile);
    QObject::connect(mFilesList, &QListWidget::itemClicked,
                     this, &FileSelectorWidget::fileClicked);
}

void FileSelectorWidget::addFile(){

    foreach(QString fPath, QFileDialog::getOpenFileNames(nullptr, "Open SVG Files", QString(), "SVG Files (*.svg)")){
        QFileInfo f(fPath);
        if( f.size() > 0 && f.exists()){
            QString filePath = f.absoluteFilePath();
            QString fileName = f.fileName();
            int num = 1;
            while( mOpenFilePaths.contains(fileName) ){
                fileName = f.fileName() + "(" + QString::number(num) + ")";
            }
            mOpenFilePaths[fileName] = filePath;
            mFilesList->addItem(fileName);
        }
    }
}

void FileSelectorWidget::removeFile(){
    for(auto item : mFilesList->selectedItems()){
        mOpenFilePaths.remove(item->text());
        mFilesList->takeItem(mFilesList->row(item));
    }
}

void FileSelectorWidget::fileClicked(QListWidgetItem *item){
    if(item->text().size() > 0){
        mCurrentFilePath = mOpenFilePaths[item->text()];
        setWindowTitle(mCurrentFilePath);
        emit selectedFile(mCurrentFilePath);
    }
}
