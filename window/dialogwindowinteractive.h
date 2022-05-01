#ifndef DIALOGWINDOWINTERACTIVE_H
#define DIALOGWINDOWINTERACTIVE_H

#include <QDialog>
#include "dialogchildwindow.h"

namespace Ui {
class DialogWindowInteractive;
}

class DialogWindowInteractive : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWindowInteractive(QWidget *parent = nullptr);
    ~DialogWindowInteractive();

private:
    Ui::DialogWindowInteractive *ui;
    DialogChildWindow* childWindow = new DialogChildWindow;

private slots:
    void receiveData(QString data); // 接收数据

signals:
    void  sendData(QString); // 发送数据
};

#endif // DIALOGWINDOWINTERACTIVE_H
