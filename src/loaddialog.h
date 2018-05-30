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
    void enableSandwich();
    void runClicked();

private:
    /* CF stands for Config File */
    QLineEdit *mCfPath;

    /* OD stands for Output Directory */
    QLineEdit *mOdPath;

    /* TODO: use signal/slots */
    QToolButton *mRunButton;
};

#endif // LOADDIALOG_H
