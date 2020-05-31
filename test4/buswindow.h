#ifndef BUSWINDOW_H
#define BUSWINDOW_H

#include <QMainWindow>
#include "bus.h"
#include "data.h"
#include "time.h"
namespace Ui {
class BusWindow;
}

class BusWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BusWindow(QWidget *parent = 0);
    ~BusWindow();
    bool cantakebus();
    int bus_choose;

private slots:
    void on_button_ok_clicked();

    void on_button_sure1_clicked();

    void on_button_sure2_clicked();

private:
    Ui::BusWindow *ui;
    bus *busdata[11][2];

};

#endif // BUSWINDOW_H
