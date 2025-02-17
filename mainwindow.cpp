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

    // 基本控件 =============================================
    connect(ui->pushButton_combo_box,&QPushButton::clicked,[=]{
        combobox->setModal(true);
        combobox->show();
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
    connect(ui->pushButton_window_monaco_editor,&QPushButton::clicked,[=]{
        window_monaco_editor->show();
    });


    connect(ui->pushButton_window_listwidget,&QPushButton::clicked,[=]{ window_listwidget->show(); });
    // ================================ 项目(基于模型) =================================================

    // 列表视图
    connect(ui->pushButton_window_listview,&QPushButton::clicked,[=]{
        window_listview->show();
    });

    // 表格视图 =============================================
    connect(ui->pushButton_window_tableview,&QPushButton::clicked,[=]{
        window_tableview->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

