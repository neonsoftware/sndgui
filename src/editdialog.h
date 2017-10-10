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
    void addFile();
    void removeFile();
    void loadFile();
    void previewSvg();
    void saveCode();
    void modified();
    void fileClicked(QListWidgetItem *item);

private:

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
