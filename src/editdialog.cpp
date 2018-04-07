#include "editdialog.h"
#include "xmlsyntax.h"
#include <QDebug>

SvgEditorDialog::SvgEditorDialog(QWidget *parent) : QWidget(parent),
    mFileSelector(new FileSelectorWidget),
    mSvgEditor(new SvgEditorWidget),
    mSvgPreviewer(new SvgPreviewWidget)
{
    QSplitter *spli = new QSplitter;
    spli->setContentsMargins(0,0,0,0);
    spli->setHandleWidth(1);
    spli->addWidget(mFileSelector);
    spli->addWidget(mSvgEditor);
    spli->addWidget(mSvgPreviewer);

    QHBoxLayout *hl = new QHBoxLayout;
    hl->setContentsMargins(0,0,0,0);
    hl->setSpacing(0);
    hl->addWidget(spli);
    this->setLayout(hl);
}

EditDialog::EditDialog(QWidget *parent) : QWidget(parent),
    mFilesList(new QListWidget),
    mFlVl(new QVBoxLayout),
    mFlHl(new QHBoxLayout),
    mButtonAdd(new QToolButton),
    mButtonRemove(new QToolButton),
    mCodeEditor(new QPlainTextEdit),
    mCeVl(new QVBoxLayout),
    mCeHl(new QHBoxLayout),
    mButtonSave(new QToolButton),
    mButtonPreview(new QToolButton),
    mSVGColumn(new QWidget),
    mSVGRendered(new QSvgWidget)
{
    // File List
    mFilesList->horizontalScrollBar()->setEnabled(false);
    mFilesList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //qDebug() << "min" << mFlVl->sizeConstraint().;

    // Editor
    mButtonSave->setText("save");
    mButtonPreview->setText("preview");
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

    QSplitter *spli = new QSplitter;
    QWidget *flW = new QWidget;
    flW->setLayout(mFlVl);
    flW->setContentsMargins(0,0,0,0);

    QWidget *ceW = new QWidget;
    ceW->setLayout(mCeVl);

    spli->setContentsMargins(0,0,0,0);
    spli->setHandleWidth(1);

    mSVGColumn = new QWidget;
    QVBoxLayout *vSVGl = new QVBoxLayout;
    QHBoxLayout *hSVGl = new QHBoxLayout;
    hSVGl->addStretch();
    hSVGl->addWidget(mSVGRendered);
    hSVGl->addStretch();
    vSVGl->addStretch();
    vSVGl->addLayout(hSVGl);
    vSVGl->addStretch();
    mSVGColumn->setLayout(vSVGl);

    spli->addWidget(flW);
    spli->addWidget(ceW);
    spli->addWidget(mSVGColumn);

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
    QObject::connect(mCodeEditor->document(), &QTextDocument::modificationChanged,
                     this, &EditDialog::modified);

    QHBoxLayout *hl = new QHBoxLayout;
    hl->setContentsMargins(0,0,0,0);
    hl->setSpacing(0);
    hl->addWidget(spli);
    this->setLayout(hl);
}

void EditDialog::createLayouts(){
}

void EditDialog::addFile(){

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

void EditDialog::modified(){
    qDebug() << "modified !!!";
    mCodeEditor->document()->isModified();
}

void EditDialog::removeFile(){
    for(auto item : mFilesList->selectedItems()){
        mOpenFilePaths.remove(item->text());
        mFilesList->takeItem(mFilesList->row(item));
    }
}

void EditDialog::fileClicked(QListWidgetItem *item){
    if(item->text().size() > 0){
        mCurrentFilePath = mOpenFilePaths[item->text()];
        setWindowTitle(mCurrentFilePath);
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
    qDebug() << "size: " << mSVGRendered->sizeHint();
    QSize s = mSVGRendered->sizeHint();
    float ratio = ((float)s.width())/s.height();
    int w = mSVGColumn->size().width();
    int h = ratio * w;
    QSize n;
    n.setHeight(h);
    n.setWidth(w);
    mSVGRendered->setFixedSize(n);
}

void EditDialog::saveCode(){

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
