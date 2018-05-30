#include "loaddialog.h"
#include "sndwch.h"

#include "QSvgWidget"

LoadDialog::LoadDialog(QWidget *parent) : QWidget(parent)
{



    QToolButton *mCfButton = new QToolButton; 
    QToolButton *mOdButton = new QToolButton;
    QToolButton *mRunButton = new QToolButton;

    QHBoxLayout *mCfHl = new QHBoxLayout;
    QHBoxLayout *mOdHl = new QHBoxLayout;

    mCfPath = new QLineEdit;
    mOdPath = new QLineEdit;
    
    mCfButton->setText("...");
    mOdButton->setText("...");
    
    mCfHl->addWidget(mCfPath);
    mCfHl->addWidget(mCfButton);

    mOdHl->addWidget(mOdPath);
    mOdHl->addWidget(mOdButton);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("Config file:"), mCfHl);
    formLayout->addRow(tr("Output folder:"), mOdHl);
    
    mRunButton->setText("sandwich");
    mRunButton->setEnabled(false);

    QHBoxLayout *mRunLayout = new QHBoxLayout;
    mRunLayout->addStretch();
    mRunLayout->addWidget(mRunButton);


    QObject::connect(mCfButton, &QToolButton::clicked,
                     this, &LoadDialog::selectCfClicked);
    QObject::connect(mCfButton, &QToolButton::clicked,
                     this, &LoadDialog::enableSandwich);
    QObject::connect(mOdButton, &QToolButton::clicked,
                     this, &LoadDialog::selectOdClicked);
    QObject::connect(mOdButton, &QToolButton::clicked,
                     this, &LoadDialog::enableSandwich);
    QObject::connect(mRunButton, &QToolButton::clicked,
                     this, &LoadDialog::runClicked);

    QSvgWidget *svgIcon = new QSvgWidget;
    svgIcon->load(QString(":/resources/stack_2.svg"));
    svgIcon->setFixedSize(120,120);

    QHBoxLayout *iHL = new QHBoxLayout;
    iHL->addStretch();
    iHL->addWidget(svgIcon);
    iHL->addStretch();
    iHL->setEnabled(false);


    QVBoxLayout *ll = new QVBoxLayout;
    ll->addLayout(formLayout);
    //ll->addLayout(iHL);
    ll->addLayout(mRunLayout);
    ll->addStretch();
    
    this->setLayout(ll);
}

void LoadDialog::selectCfClicked(){
    QString cf = QFileDialog::getOpenFileName();
    if( ! cf.isEmpty() )
            mCfPath->setText(cf);
}

void LoadDialog::enableSandwich(){
    if( ! mCfPath->text().isEmpty() && ! mOdPath->text().isEmpty())
            mRunButton->setEnabled(true);
}

void LoadDialog::selectOdClicked(){
    QString od = QFileDialog::getExistingDirectory();
    if( ! od.isEmpty() )
            mOdPath->setText(od);    
}

void LoadDialog::runClicked(){
    snd_err_t res = swc_sandwich(mCfPath->text().toStdString().c_str(), mOdPath->text().toStdString().c_str());
    if (res != SWC_OK)
        QMessageBox::warning(this, "result", "Error Creating.");
    else
        QMessageBox::information(this, "result", "Ok !");
}
