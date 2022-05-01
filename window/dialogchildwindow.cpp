#include "dialogchildwindow.h"
#include "ui_dialogchildwindow.h"

DialogChildWindow::DialogChildWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChildWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("子窗口");
    connect(ui->pushButton_send,&QPushButton::clicked,[=]{
        emit sendData(ui->lineEdit_send->text());
    });
    ui->pushButton_receive->setDisabled(true);
}

DialogChildWindow::~DialogChildWindow()
{
    delete ui;
}

void DialogChildWindow::receiveData(QString data)
{
    ui->lineEdit_receive->setText(data);
}
