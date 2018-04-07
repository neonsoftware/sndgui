#include "SvgPreviewWidget.h"
#include <QDebug>

SvgPreviewWidget::SvgPreviewWidget(QWidget *parent) : QWidget(parent),
    mSVGRendered(new QSvgWidget)
{
    QVBoxLayout *vSVGl = new QVBoxLayout;
    QHBoxLayout *hSVGl = new QHBoxLayout;
    hSVGl->addStretch();
    hSVGl->addWidget(mSVGRendered);
    hSVGl->addStretch();
    vSVGl->addStretch();
    vSVGl->addLayout(hSVGl);
    vSVGl->addStretch();
    mSVGRendered->setStyleSheet("background-color: white; border:0px;");
    this->setLayout(vSVGl);
}

void SvgPreviewWidget::previewSvg(QString pSvgFile){

    //mSVGRendered->load(mCodeEditor->toPlainText().toUtf8());
    mSVGRendered->load(pSvgFile);
    qDebug() << "size: " << mSVGRendered->sizeHint();
    QSize s = mSVGRendered->sizeHint();
    float ratio = ((float)s.width())/s.height();
    int w = this->size().width();
    int h = ratio * w;
    QSize n;
    n.setHeight(h);
    n.setWidth(w);
    mSVGRendered->setFixedSize(n);
}
