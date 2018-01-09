#ifndef LOADDIALOG_H
#define LOADDIALOG_H

#include <QtCore>
#include <QtWidgets>

class LoadDialog : public QWidget
{
    Q_OBJECT
public:
    explicit LoadDialog(QWidget *parent = nullptr);

public slots:
    void selectCfClicked();
    void selectOdClicked();
    void runClicked();

private:
    /* CF stands for Config File */
    QLabel mCfLabel;
    QLineEdit mCfPath;
    QToolButton mCfSelect;
    QHBoxLayout mCfHl;

    /* OD stands for Output Directory */
    QLabel mOdLabel;
    QLineEdit mOdPath;
    QToolButton mOdSelect;
    QHBoxLayout mOdHl;

    QHBoxLayout mRunLayout;
    QPushButton mRunButton;

    QVBoxLayout mVl;
};

#endif // LOADDIALOG_H
