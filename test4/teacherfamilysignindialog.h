#ifndef TEACHERFAMILYSIGNINDIALOG_H
#define TEACHERFAMILYSIGNINDIALOG_H

#include <QDialog>
#include "data.h"
#include "functionselectionwindow.h"

namespace Ui {
class TeacherFamilySigninDialog;
}

class TeacherFamilySigninDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherFamilySigninDialog(QWidget *parent = 0);
    ~TeacherFamilySigninDialog();

private slots:

    void teacherfamilysignindialog_show();
    void on_buttonBox_accepted();

private:
    Ui::TeacherFamilySigninDialog *ui;
    FunctionSelectionWindow *fs;
};

#endif // TEACHERFAMILYSIGNINDIALOG_H
