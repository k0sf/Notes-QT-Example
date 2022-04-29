#include "progressbar.h"
#include "ui_progressbar.h"

progressbar::progressbar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::progressbar)
{
    ui->setupUi(this);
    this->setBaseSize(650,300);
    this->setWindowTitle("进度条");
    ui->spinBox_min->setMaximum(INT_MAX);
    ui->spinBox_max->setMinimum(100);
    ui->spinBox_max->setMaximum(INT_MAX);
    ui->spinBox_min->setValue(INT_MIN);
    ui->spinBox_max->setValue(100000);
    ui->label->setText("");

#ifdef Q_OS_WINDOWS
    ui->progressBar->setAlignment(Qt::AlignCenter);
#endif
    connect(this->ui->pushButton,&QPushButton::clicked,[=]{
        ui->pushButton->setDisabled(true); // 禁用启动按钮
        ui->progressBar->setRange(ui->spinBox_min->value(),ui->spinBox_max->value());
        for (int var = 0; var <= ui->progressBar->maximum(); ++var) {
            ui->progressBar->setValue(var);
            // 计算百分比的值
            int xnum = (ui->progressBar->value() - ui->progressBar->minimum())*100/(ui->progressBar->maximum() - ui->progressBar->minimum());
            QString text = QString("当前进度: %1% (%2/%3)").arg(QString::number(xnum)).arg(ui->progressBar->value()).arg(ui->progressBar->maximum());
#ifdef Q_OS_MACOS
            ui->label->setText(text);
#else
            ui->progressBar->setFormat(text);
#endif
            QCoreApplication::processEvents(); //不停地处理事件，让程序保持响应
        }
        ui->pushButton->setDisabled(false);
    });
}

progressbar::~progressbar()
{
    delete ui;
}
