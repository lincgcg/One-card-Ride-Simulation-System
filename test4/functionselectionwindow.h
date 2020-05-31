#ifndef FUNCTIONSELECTIONWINDOW_H
#define FUNCTIONSELECTIONWINDOW_H
#define STUDENT 0
#define TEACHER 1
#define TEACHER_FAMILY 2

#include <QMainWindow>
#include "people.h"
#include <qmessagebox.h>
#include "data.h"
#include <QString>
#include "rechargewindows.h"
#include <QImage>
#include <QPixmap>
#include "buswindow.h"

namespace Ui {
class FunctionSelectionWindow;
}

class FunctionSelectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FunctionSelectionWindow(QWidget *parent = 0);

    student *stu_user;
    teacher *tea_user;
    teacher_family *teafam_user;

    int user_id;

    RechargeWindows *re;

    BusWindow  *bi;

    ~FunctionSelectionWindow();
private slots:
    void on_ride_button_clicked();

    void on_quit_button_clicked();

    void on_recharge_button_clicked();

    void on_logout_button_clicked();

private:
    Ui::FunctionSelectionWindow *ui;
};

#endif // FUNCTIONSELECTIONWINDOW_H
