#ifndef SVGPREVIEWWIDGET_H
#define SVGPREVIEWWIDGET_H

#include <QtCore>
#include <QtWidgets>
#include <QtSvg>

class SvgPreviewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SvgPreviewWidget(QWidget *parent = nullptr);

public slots:
    void previewSvg(QString svgFile);

private:
    QSvgWidget *mSVGRendered;
};

#endif // SVGEDITORWIDGET_H
