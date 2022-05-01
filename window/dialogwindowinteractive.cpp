#include "dialogwindowinteractive.h"
#include "ui_dialogwindowinteractive.h"

DialogWindowInteractive::DialogWindowInteractive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindowInteractive)
{
    ui->setupUi(this);
    this->setWindowTitle("父窗口");

    connect(childWindow,SIGNAL(sendData(QString)),SLOT(receiveData(QString)));
    connect(ui->pushButton_open,&QPushButton::clicked,[=]{
        childWindow->show();
    });

    connect(ui->pushButton_send,&QPushButton::clicked,[=]{
        connect(this,SIGNAL(sendData(QString)),childWindow,SLOT(receiveData(QString)));
        emit sendData(ui->lineEdit_send->text());
    });
    ui->pushButton_receive->setDisabled(true);
}

DialogWindowInteractive::~DialogWindowInteractive()
{
    delete ui;
}

void DialogWindowInteractive::receiveData(QString data)
{
    ui->lineEdit_receive->setText(data);
}
