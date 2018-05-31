#ifndef SVGEDITDIALOG_H
#define SVGEDITDIALOG_H

#include <QtCore>
#include <QtWidgets>
#include <QtSvg>

#include "FileSelectorWidget.h"
#include "SvgEditorWidget.h"
#include "SvgPreviewWidget.h"

class SvgEditorDialog : public QWidget
{
    Q_OBJECT
public:
    explicit SvgEditorDialog(QWidget *parent = nullptr);

private:
    FileSelectorWidget *mFileSelector;
    SvgEditorWidget *mSvgEditor;
    SvgPreviewWidget *mSvgPreviewer;
};

#endif // SVGEDITDIALOG_H
