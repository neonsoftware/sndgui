#include "loaddialog.h"
#include "sndwch.h"

#include "QSvgWidget"

LoadDialog::LoadDialog(QWidget *parent) : QWidget(parent)
{
    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mCfLabel.setText("Config file");
    mCfSelect.setText("...");
    //mCfSelect.setFixedSize(QSize(100, 100));
    //mCfSelect.setIcon(QIcon(":/if_plus.svg"));
    //mCfSelect.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //mCfSelect.setIconSize(QSize(100, 100));
    //mCfHl.addWidget(&mCfLabel);
    mCfHl.addWidget(&mCfPath);
    mCfHl.addWidget(&mCfSelect);

    mOdLabel.setText("Output directory");
    mOdSelect.setText("...");
    //mOdHl.addWidget(&mOdLabel);
    mOdHl.addWidget(&mOdPath);
    mOdHl.addWidget(&mOdSelect);

    mRunButton.setText("sandwich");
    mRunLayout.addWidget(&mRunButton);
    mRunButton.setEnabled(false);

    QObject::connect(&mCfSelect, &QToolButton::clicked,
                     this, &LoadDialog::selectCfClicked);
    QObject::connect(&mCfSelect, &QToolButton::clicked,
                     this, &LoadDialog::enableSandwich);
    QObject::connect(&mOdSelect, &QToolButton::clicked,
                     this, &LoadDialog::selectOdClicked);
    QObject::connect(&mOdSelect, &QToolButton::clicked,
                     this, &LoadDialog::enableSandwich);
    QObject::connect(&mRunButton, &QToolButton::clicked,
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
    ll->addWidget(&mCfLabel);
    ll->addLayout(&mCfHl);
    ll->addWidget(&mOdLabel);
    ll->addLayout(&mOdHl);
    ll->addLayout(iHL);
    ll->addLayout(&mRunLayout);


    this->setLayout(ll);
}

void LoadDialog::selectCfClicked(){
    QString cf = QFileDialog::getOpenFileName();
    if( ! cf.isEmpty() )
            mCfPath.setText(cf);
}

void LoadDialog::enableSandwich(){
    if( ! mCfPath.text().isEmpty() && ! mOdPath.text().isEmpty())
            mRunButton.setEnabled(true);
}

void LoadDialog::selectOdClicked(){
    QString od = QFileDialog::getExistingDirectory();
    if( ! od.isEmpty() )
            mOdPath.setText(od);    
}

void LoadDialog::runClicked(){
    snd_err_t res = swc_sandwich(mCfPath.text().toStdString().c_str(), mOdPath.text().toStdString().c_str());
    if (res != SWC_OK)
        QMessageBox::warning(this, "result", "Error Creating.");
    else
        QMessageBox::information(this, "result", "Ok !");
}
