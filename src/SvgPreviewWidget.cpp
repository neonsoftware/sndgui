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
    mSVGRendered->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setLayout(vSVGl);
}

void SvgPreviewWidget::previewSvg(QString pSvgFile){

    mSVGRendered->load(pSvgFile);
    return;

    /*
    qDebug() << "size: " << mSVGRendered->sizeHint() << " current w" << this->size().width() << " h" << this->size().height();
    QSize svg_original_size = mSVGRendered->sizeHint();

    // TODO slightly diminish size to take borders into account.
    QSize widget_size = this->size(); 
    const int pixel_extra = 15;
    float h_ratio = (float) (widget_size.height() - pixel_extra) / svg_original_size.height();
    float w_ratio = (float) (widget_size.width() - pixel_extra ) / svg_original_size.width();
    float ratio = std::min(w_ratio, h_ratio);    
    qDebug() << "set: " << ratio * svg_original_size.width() << "," << ratio * svg_original_size.height();
    mSVGRendered->setFixedSize(QSize(ratio * svg_original_size.width(), ratio * svg_original_size.height()));
    */
}
