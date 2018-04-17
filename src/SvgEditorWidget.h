#ifndef SVGEDITORWIDGET_H
#define SVGEDITORWIDGET_H

#include <QtCore>
#include <QtWidgets>

class SvgEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SvgEditorWidget(QWidget *parent = nullptr);

signals:
    void saved(QString selectedFilePath);
    void modified(QString selectedFilePath);

public slots:
    void loadFile(QString selectedFilePath);
    void saveCode();

private:
    // Editor
    QPlainTextEdit *mCodeEditor;
    QVBoxLayout *mCeVl;
    QHBoxLayout *mCeHl;
    QToolButton *mButtonSave;
    QToolButton *mButtonPreview;
    QString mCurrentFilePath;
};

#endif // SVGEDITORWIDGET_H
