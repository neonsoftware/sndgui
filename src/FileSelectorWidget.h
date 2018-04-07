#ifndef FILESELECTORWIDGET_H
#define FILESELECTORWIDGET_H

#include <QtCore>
#include <QtWidgets>

class FileSelectorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FileSelectorWidget(QWidget *parent = nullptr);

signals:
    void selectedFile(QString selectedFilePath);

public slots:
    void addFile();
    void removeFile();
    void fileClicked(QListWidgetItem *item);

private:
    void createLayouts();

    // File List
    QListWidget *mFilesList;
    QVBoxLayout *mFlVl;
    QHBoxLayout *mFlHl;
    QToolButton *mButtonAdd;
    QToolButton *mButtonRemove;

    // Glue
    QString mCurrentFilePath;

    QMap<QString, QString> mOpenFilePaths;
};

#endif // FILESELECTORWIDGET_H
