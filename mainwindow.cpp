#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("笔记-QT实例集合");

    connect(ui->pushButton_progressbar,&QPushButton::clicked,[=]{
        if(pbarWindow->isHidden()){
            pbarWindow->show();
        }
    });

    // 窗口 =============================================
    connect(ui->pushButton_window_interactive,&QPushButton::clicked,[=]{
//        windowInteractive->setModal(true);
        windowInteractive->show();
    });

    // 代码编辑 =============================================
    connect(ui->pushButton_window_ace_editor,&QPushButton::clicked,[=]{
        window_ace_editor->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

