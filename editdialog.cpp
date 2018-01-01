#include "editdialog.h"
#include "style.h"
#include "BasicXMLSyntaxHighlighter.h"

EditDialog::EditDialog(QWidget *parent) : QWidget(parent)
{

    // File List
    mFilesList = new QListWidget;
    mFlVl = new QVBoxLayout;
    mFlHl = new QHBoxLayout;
    mButtonAdd = new QToolButton;
    mButtonRemove = new QToolButton;

    // Editor
    mCodeEditor = new QPlainTextEdit;
    mCeVl = new QVBoxLayout;
    mCeHl = new QHBoxLayout;
    mButtonSave = new QToolButton;
    mButtonPreview = new QToolButton;

    mSVGRendered = new QSvgWidget;

    mButtonSave->setText("save");
    mButtonPreview->setText("preview");
    mButtonAdd->setText("+");
    mButtonRemove->setText("-");

    QPalette p;
    p.setColor(QPalette::Background, sndgui_style.col_base);

    QWidget *mFlW = new QWidget;
    mFlW->setAutoFillBackground(true);
    mFlW->setPalette(p);
    mFlHl->setContentsMargins(3,3,3,3);
    mFlHl->setSpacing(3);
    mFlHl->addWidget(mButtonAdd);
    mFlHl->addWidget(mButtonRemove);
    mFlHl->addStretch();
    mFlW->setLayout(mFlHl);

    mFlVl->addWidget(mFilesList);
    mFlVl->addWidget(mFlW);
    mFlVl->setContentsMargins(0,0,0,0);
    mFlVl->setSpacing(0);

    QWidget *mCeW = new QWidget;
    mCeW->setAutoFillBackground(true);
    mCeW->setPalette(p);
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

    QSplitter *spli = new QSplitter;
    //spli->setOrientation(Qt::Vertical);
    QWidget *flW = new QWidget;
    flW->setLayout(mFlVl);
    flW->setContentsMargins(0,0,0,0);

    QWidget *ceW = new QWidget;
    ceW->setLayout(mCeVl);

    spli->setContentsMargins(0,0,0,0);
    //spli->setHandleWidth(2);

    spli->addWidget(flW);
    spli->addWidget(ceW);
    spli->addWidget(mSVGRendered);

    mSVGRendered->setStyleSheet("background-color: white; border:0px;");
    mCodeEditor->setStyleSheet("border:0px;");
    mFilesList->setStyleSheet("border:0px;");

    new BasicXMLSyntaxHighlighter(mCodeEditor->document());

    QObject::connect(mButtonAdd, &QToolButton::clicked,
                     this, &EditDialog::addFile);
    QObject::connect(mButtonPreview, &QToolButton::clicked,
                     this, &EditDialog::previewSvg);
    QObject::connect(mButtonSave, &QToolButton::clicked,
                     this, &EditDialog::saveCode);
    QObject::connect(mButtonRemove, &QToolButton::clicked,
                     this, &EditDialog::removeFile);
    QObject::connect(mFilesList, &QListWidget::itemClicked,
                     this, &EditDialog::fileClicked);

    QHBoxLayout *hl = new QHBoxLayout;
    hl->setContentsMargins(0,0,0,0);
    hl->setSpacing(0);
    hl->addWidget(spli);
    this->setLayout(hl);
}

void EditDialog::addFile(){
    mCurrentFilePath = QFileDialog::getOpenFileName();
    if( mCurrentFilePath.size() > 0 ){
        mFilesList->addItem(mCurrentFilePath);
    }
}

void EditDialog::removeFile(){
    for(auto item : mFilesList->selectedItems()){
        mFilesList->takeItem(mFilesList->row(item));
    }
}

void EditDialog::fileClicked(QListWidgetItem *item){
    if(item->text().size() > 0){
        mCurrentFilePath = item->text();
        loadFile();
    }
}

void EditDialog::loadFile(){

    if( mCurrentFilePath.size() > 0 ){
        QFile file(mCurrentFilePath);
        if( file.open(QFile::ReadOnly | QFile::Text) ){
            mCodeEditor->setPlainText(file.readAll());
            file.close();
            previewSvg();
        }
    }
}

void EditDialog::previewSvg(){
    mSVGRendered->load(mCodeEditor->toPlainText().toUtf8());
    mSVGRendered->setSizeIncrement(mSVGRendered->sizeHint());
}

void EditDialog::saveCode(){

    if( mCurrentFilePath.size() > 0 ){
        QFile file(mCurrentFilePath);
        if( file.open(QFile::WriteOnly | QFile::Text) ){
            QTextStream o(&file);
            o << mCodeEditor->toPlainText();
            o.flush();
            file.close();
        }
    }
}
