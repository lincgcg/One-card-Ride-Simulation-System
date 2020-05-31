#ifndef STUDENTSIGNINDIALOG_H
#define STUDENTSIGNINDIALOG_H

#include <QDialog>
#include "data.h"
#include "functionselectionwindow.h"

namespace Ui {
class StudentSigninDialog;
}

class StudentSigninDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentSigninDialog(QWidget *parent = 0);
    ~StudentSigninDialog();

private slots:

    void studentsignindialog_show();
    void on_buttonBox_accepted();

private:
    Ui::StudentSigninDialog *ui;
    FunctionSelectionWindow *fs;
};

#endif // STUDENTSIGNINDIALOG_H


