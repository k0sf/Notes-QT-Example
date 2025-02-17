#include "dialogtableview.h"
#include "ui_dialogtableview.h"
#include <QStandardItemModel>

DialogTableView::DialogTableView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogTableView)
{
    ui->setupUi(this);

    this->setWindowTitle("Table View - 表格视图");

    // QStringList heardList;heardList<<"name"<<"desc"<<"xxx";
    // QHeaderView *hearview = new QHeaderView(Qt::Horizontal);
    // QStandardItemModel* model = new QStandardItemModel;
    // model->setHorizontalHeaderLabels(heardList);
    // hearview->setModel(model);
    // model->setHeaderData();
    // ui->tableView->setHorizontalHeader(hearview);

    ui->tableView->setModel(model);
    ui->tableView->setStyleSheet("QHeaderView::section{ font-size:12px; }"
                                         "QTableView { font-size:10px; }");
    ui->tableView->setAlternatingRowColors(true); // 隔行换色
    // ui->tableView->resizeRowsToContents();// 调整行高自适应内容
    ui->tableView->verticalHeader()->setDefaultSectionSize(10); // 所有列的默认行高
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 设置选择行为: 整行选择
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 设置最后一列填充整个表头
    // ui->tableView->horizontalHeader()->setVisible(true);
    model->add(StructTable{1,"hello","descsdfsdf",true});

    // 自定义
    ui->tableView_2->setModel(cmodel);
    ui->tableView_2->setItemDelegate(cd);
    cmodel->add(CustomStructTable{"xxxx",true,false,20,"我是按钮",false});
    cmodel->add(CustomStructTable{"xxxx",false,true,30,"我是按钮",true});
}

DialogTableView::~DialogTableView()
{
    delete ui;
}
