#ifndef DIALOGCHILDWINDOW_H
#define DIALOGCHILDWINDOW_H

#include <QDialog>

namespace Ui {
class DialogChildWindow;
}

class DialogChildWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChildWindow(QWidget *parent = nullptr);
    ~DialogChildWindow();

private:
    Ui::DialogChildWindow *ui;

private slots:
    void receiveData(QString data); // 接收数据

signals:
    void  sendData(QString); // 发送数据
};

#endif // DIALOGCHILDWINDOW_H
