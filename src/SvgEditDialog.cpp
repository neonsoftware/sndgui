#include "SvgEditDialog.h"
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

    QObject::connect(mFileSelector, &FileSelectorWidget::selectedFile,
                     mSvgEditor, &SvgEditorWidget::loadFile);
    
    QObject::connect(mSvgEditor, &SvgEditorWidget::saved,
		     mSvgPreviewer, &SvgPreviewWidget::previewSvg);
}
