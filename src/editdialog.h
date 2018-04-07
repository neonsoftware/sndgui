#ifndef EDITDIALOG_H
#define EDITDIALOG_H

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

class EditDialog : public QWidget
{
    Q_OBJECT
public:
    explicit EditDialog(QWidget *parent = nullptr);

public slots:
    void addFile();
    void removeFile();
    void loadFile();
    void previewSvg();
    void saveCode();
    void modified();
    void fileClicked(QListWidgetItem *item);

private:

    void createLayouts();

    // File List
    QListWidget *mFilesList;
    QVBoxLayout *mFlVl;
    QHBoxLayout *mFlHl;
    QToolButton *mButtonAdd;
    QToolButton *mButtonRemove;

    // Editor
    QPlainTextEdit *mCodeEditor;
    QVBoxLayout *mCeVl;
    QHBoxLayout *mCeHl;
    QToolButton *mButtonSave;
    QToolButton *mButtonPreview;

    // Svg Preview
    QWidget *mSVGColumn;
    QSvgWidget *mSVGRendered;

    // Glue
    QString mCurrentFilePath;

    QMap<QString, QString> mOpenFilePaths;
};

#endif // EDITDIALOG_H
