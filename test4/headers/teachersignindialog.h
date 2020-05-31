#ifndef TEACHERSIGNINDIALOG_H
#define TEACHERSIGNINDIALOG_H

#include <QDialog>
#include "data.h"
#include "functionselectionwindow.h"

namespace Ui {
class TeacherSigninDialog;
}

class TeacherSigninDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherSigninDialog(QWidget *parent = 0);
    ~TeacherSigninDialog();

private slots:

    void teachersignindialog_show();
    void on_buttonBox_accepted();

private:
    Ui::TeacherSigninDialog *ui;
    FunctionSelectionWindow *fs;

};

#endif // TEACHERSIGNINDIALOG_H
