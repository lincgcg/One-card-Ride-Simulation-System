#ifndef LOGONMAINWINDOW_H
#define LOGONMAINWINDOW_H

#include <QMainWindow>
#include <functionselectionwindow.h>

namespace Ui {
class LogonMainWindow;
}

class LogonMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogonMainWindow(QWidget *parent = 0);
    ~LogonMainWindow();

    int identity;
private slots:
    void logonMainwindow_show();

    void on_button_identity_clicked();

    void on_button_sure_clicked();

private:
    Ui::LogonMainWindow *ui;
};

#endif // LOGONMAINWINDOW_H
