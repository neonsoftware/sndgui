#include "SvgEditorWidget.h"
#include "xmlsyntax.h"
#include <QDebug>

SvgEditorWidget::SvgEditorWidget(QWidget *parent) : QWidget(parent),
    mCodeEditor(new QPlainTextEdit),
    mCeVl(new QVBoxLayout),
    mCeHl(new QHBoxLayout),
    mButtonSave(new QToolButton),
    mButtonPreview(new QToolButton)
{
    mButtonSave->setText("save");
    mButtonPreview->setText("preview");

    QWidget *mCeW = new QWidget;
    mCeW->setAutoFillBackground(true);
    mCeHl->addWidget(mButtonSave);
    mCeHl->addWidget(mButtonPreview);
    mCeHl->addStretch();
    mCeHl->setContentsMargins(3,3,3,3);
    mCeHl->setSpacing(3);
    mCeW->setLayout(mCeHl);


    mCeVl->addWidget(mCodeEditor);
    mCeVl->addWidget(mCeW);
    mCeVl->setContentsMargins(0,0,0,0);
    mCeVl->setSpacing(0);

    mCodeEditor->setStyleSheet("border:0px;");

    new BasicXMLSyntaxHighlighter(mCodeEditor->document());
    this->setLayout(mCeVl);

    //QObject::connect(mButtonPreview, &QToolButton::clicked,
    //                 this, &SvgEditorWidget::previewSvg);
    QObject::connect(mButtonSave, &QToolButton::clicked,
                     this, &SvgEditorWidget::saveCode);
}

void SvgEditorWidget::loadFile(QString selectedFilePath){

    if( selectedFilePath.size() > 0 ){
        mCurrentFilePath = selectedFilePath;
        QFile file(selectedFilePath);
        if( file.open(QFile::ReadOnly | QFile::Text) ){
            mCodeEditor->setPlainText(file.readAll());
            file.close();
            //previewSvg();
        }
    }
}

void SvgEditorWidget::saveCode(){
  
    if( mCurrentFilePath.size() > 0 ){
        QFile file(mCurrentFilePath);
        if( file.open(QFile::WriteOnly | QFile::Text) ){
            QTextStream o(&file);
            o << mCodeEditor->toPlainText();
            o.flush();
            file.close();
            mCodeEditor->document()->setModified(false);
        }
    }
}

