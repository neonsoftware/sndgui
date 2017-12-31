#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QtCore>
#include <QtWidgets>
#include <QtSvg>

class EditDialog : public QWidget
{
    Q_OBJECT
public:
    explicit EditDialog(QWidget *parent = nullptr);

public slots:
    void openFileClicked();
    void previewSvg();
    void saveCode();

private:

    QToolButton mButtonCodeSave;
    QToolButton mButtonCodePreview;
    QToolButton mButtonFileOpen;
    QPlainTextEdit mCodeEditor;
    QSvgWidget mSVGRendered;
    QHBoxLayout mHl;
    QTemporaryFile mTempFile;
    QString mCurrentFilePath;
};

#endif // EDITDIALOG_H
