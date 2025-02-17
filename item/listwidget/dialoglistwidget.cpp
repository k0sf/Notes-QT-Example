#include "dialoglistwidget.h"
#include "ui_dialoglistwidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

DialogListWidget::DialogListWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogListWidget)
{
    ui->setupUi(this);


    for (int i = 0; i < 5; ++i){
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);


        QWidget *widget = new QWidget;
        QHBoxLayout *mainLayout = new QHBoxLayout(widget);
        mainLayout->setContentsMargins(1,1,1,1);

        QVBoxLayout *leftLayout = new QVBoxLayout;
        leftLayout->setSpacing(1); // 设置布局间距为10像素
        QLabel *label = new QLabel("Item " + QString::number(i));
        QProgressBar *progressBar = new QProgressBar;
        progressBar->setValue((i + 1) * 20);

        QHBoxLayout *rightLayout = new QHBoxLayout;
        QPushButton *button = new QPushButton("暂停/启动");
        QPushButton *button2 = new QPushButton("取消");

        leftLayout->addWidget(label);
        leftLayout->addWidget(progressBar);

        rightLayout->addWidget(button);
        rightLayout->addWidget(button2);

        mainLayout->addLayout(leftLayout);
        mainLayout->addLayout(rightLayout);

        item->setSizeHint(widget->sizeHint());
        ui->listWidget->setItemWidget(item, widget);
    }


}

DialogListWidget::~DialogListWidget()
{
    delete ui;
}
