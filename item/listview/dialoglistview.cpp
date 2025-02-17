#include "dialoglistview.h"
#include "ui_dialoglistview.h"



DialogListView::DialogListView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogListView)
{
    ui->setupUi(this);

    this->setWindowTitle("List View - 列表视图");

    QStandardItemModel *model = new QStandardItemModel(ui->listView);
    CustomListViewDelegate *delegate = new CustomListViewDelegate(ui->listView);

    for (int i = 0; i < 5; ++i) {
        QStandardItem *item = new QStandardItem;
        item->setData(QString("Item %1").arg(i), Qt::DisplayRole);
        item->setData((i + 1) * 20, Qt::UserRole + 1);
        model->appendRow(item);
    }

    // 为每个项设置自定义小部件
    for (int i = 0; i < model->rowCount(); ++i) {
        QModelIndex index = model->index(i, 0);
        QString text = model->data(index, Qt::DisplayRole).toString();
        int progress = model->data(index, Qt::UserRole + 1).toInt();

        CustomListViewItemWidget *customWidget = new CustomListViewItemWidget(text, progress);
        ui->listView->setIndexWidget(index, customWidget);

        connect(customWidget, &CustomListViewItemWidget::pauseButtonClicked, [=]() {
            qDebug() << "Pause button clicked on item" << i;
        });

        connect(customWidget, &CustomListViewItemWidget::cancelButtonClicked, [=]() {
            qDebug() << "Cancel button clicked on item" << i;
        });
    }
    ui->listView->setModel(model);
    ui->listView->setItemDelegate(delegate);
    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止默认编辑

}

DialogListView::~DialogListView()
{
    delete ui;
}
