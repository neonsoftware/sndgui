#include "loaddialog.h"
#include "sndwch.h"

LoadDialog::LoadDialog(QWidget *parent) : QWidget(parent)
{
    mCfLabel.setText("Config file");
    mCfSelect.setText("...");
    mCfHl.addWidget(&mCfLabel);
    mCfHl.addWidget(&mCfPath);
    mCfHl.addWidget(&mCfSelect);

    mOdLabel.setText("Output directory");
    mOdSelect.setText("...");
    mOdHl.addWidget(&mOdLabel);
    mOdHl.addWidget(&mOdPath);
    mOdHl.addWidget(&mOdSelect);

    mRunButton.setText("run");
    mRunLayout.addWidget(&mRunButton);

    QObject::connect(&mCfSelect, &QToolButton::clicked,
                     this, &LoadDialog::selectCfClicked);
    QObject::connect(&mOdSelect, &QToolButton::clicked,
                     this, &LoadDialog::selectOdClicked);
    QObject::connect(&mRunButton, &QToolButton::clicked,
                     this, &LoadDialog::runClicked);

    QVBoxLayout *ll = new QVBoxLayout;
    ll->addLayout(&mCfHl);
    ll->addLayout(&mOdHl);
    ll->addLayout(&mRunLayout);

    this->setLayout(ll);
}

void LoadDialog::selectCfClicked(){
    QString cf = QFileDialog::getOpenFileName();
    if( cf.size() > 0 )
            mCfPath.setText(cf);
}

void LoadDialog::selectOdClicked(){
    QString od = QFileDialog::getExistingDirectory();
    if( od.size() > 0 )
            mOdPath.setText(od);
}

void LoadDialog::runClicked(){
    snd_err_t res = swc_sandwich(mCfPath.text().toStdString().c_str(), mOdPath.text().toStdString().c_str());
    if (res != SWC_OK)
        QMessageBox::warning(this, "result", "Error Creating.");
    else
        QMessageBox::information(this, "result", "Ok !");
}
