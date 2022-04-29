#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("笔记-QT实例集合");

    ui->groupBox_base->setTitle("基本控件集合");
    ui->pushButton_progressbar->setText("进度条");
    connect(ui->pushButton_progressbar,&QPushButton::clicked,[=]{
        if(pbarWindow->isHidden()){
            pbarWindow->show();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

