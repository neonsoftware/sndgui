#include "editdialog.h"
#include "BasicXMLSyntaxHighlighter.h"

EditDialog::EditDialog(QWidget *parent) : QWidget(parent)
{
    mButtonCodeSave.setText("save");
    mButtonCodePreview.setText("preview");
    mButtonFileOpen.setText("open");
    mHl.addWidget(&mButtonCodeSave);
    mHl.addWidget(&mButtonCodePreview);
    mHl.addWidget(&mButtonFileOpen);
    mHl.addWidget(&mCodeEditor);
    mHl.addWidget(&mSVGRendered);
    mCodeEditor.setPalette(mCodeEditor.style()->standardPalette());
    mCodeEditor.setStyleSheet("");
    mSVGRendered.setPalette(mSVGRendered.style()->standardPalette());
    mSVGRendered.setStyleSheet("background-color: white; border:1px solid rgb(128,128,128);");
    //->setStyleSheet("background-color: red");

    new BasicXMLSyntaxHighlighter(mCodeEditor.document());

    QObject::connect(&mButtonFileOpen, &QToolButton::clicked,
                     this, &EditDialog::openFileClicked);
    QObject::connect(&mButtonCodePreview, &QToolButton::clicked,
                     this, &EditDialog::previewSvg);
    QObject::connect(&mButtonCodeSave, &QToolButton::clicked,
                     this, &EditDialog::saveCode);

    QVBoxLayout *ll = new QVBoxLayout;
    ll->addLayout(&mHl);
    this->setLayout(ll);
}

void EditDialog::openFileClicked(){

    mCurrentFilePath = QFileDialog::getOpenFileName();

    if( mCurrentFilePath.size() > 0 ){
        QFile file(mCurrentFilePath);
        if( file.open(QFile::ReadOnly | QFile::Text) ){
            mCodeEditor.setPlainText(file.readAll());
            file.close();
            previewSvg();
        }
    }
}

void EditDialog::previewSvg(){
    mSVGRendered.load(mCodeEditor.toPlainText().toUtf8());
    mSVGRendered.setSizeIncrement(mSVGRendered.sizeHint());
}

void EditDialog::saveCode(){

    if( mCurrentFilePath.size() > 0 ){
        QFile file(mCurrentFilePath);
        if( file.open(QFile::WriteOnly | QFile::Text) ){
            QTextStream o(&file);
            o << mCodeEditor.toPlainText();
            o.flush();
            file.close();
        }
    }
}
