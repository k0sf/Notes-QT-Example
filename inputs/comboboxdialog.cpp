#include "comboboxdialog.h"
#include "ui_comboboxdialog.h"

ComboBoxDialog::ComboBoxDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ComboBoxDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("组合框 (选择框/下拉菜单)");

    // 默认组合框
    QStringList list;
    list<< "item1" << "item2" << "item3";
    ui->comboBox->addItems(list);
    ui->comboBox->setFrame(false);
    ui->checkBox_set_editable_0->setChecked(ui->comboBox->isEditable());
    if(ui->comboBox->lineEdit()){
        ui->checkBox_set_readonly_0->setChecked(ui->comboBox->lineEdit()->isReadOnly());
    }

    connect(ui->checkBox_set_readonly_0,&QCheckBox::toggled,this,[=](bool checked){
        if (ui->comboBox->lineEdit()) {
            ui->comboBox->lineEdit()->setReadOnly(checked);
        }
    });
    connect(ui->checkBox_set_editable_0,&QCheckBox::toggled,this,[=](bool checked){
        ui->comboBox->setEditable(checked);
        // 设置可编辑时，更新 readonly 复选框状态
        if (ui->comboBox->lineEdit()) {
            ui->checkBox_set_readonly_0->setChecked(ui->comboBox->lineEdit()->isReadOnly());
        } else {
            // 如果不可编辑，则禁用 readonly 复选框
            ui->checkBox_set_readonly_0->setChecked(false);
        }
    });






    // 创建一个菜单
    QMenu *menu = new QMenu();
    QAction *item = menu->addAction("Option 1");
    menu->addSeparator();
    QMenu *category1= menu->addMenu("分类 1");
    category1->addAction("子分类 1.1");
    category1->addAction("子分类 1.2");

    // 自定义组合框
    MenuComboBox *comboBox = new MenuComboBox();
    comboBox->setMenu(menu);

    connect(item, &QAction::triggered, comboBox, [comboBox]() {
        qInfo()<<"点击选项1"<<comboBox->currentText();
    });
    // QObject::connect(item, &QAction::triggered, comboBox, [comboBox]() {
    //     comboBox->setCurrentText("Option 1");
    // });
    if(ui->groupBox->layout()){
        ui->groupBox->layout()->addWidget(comboBox);
    }

    ui->checkBox_set_editable->setChecked(comboBox->isEditable());
    if(comboBox->lineEdit()){
        ui->checkBox_set_readonly->setChecked(comboBox->lineEdit()->isReadOnly());
    }
    connect(ui->checkBox_set_readonly,&QCheckBox::toggled,this,[=](bool checked){
        if (comboBox->lineEdit()) {
            comboBox->lineEdit()->setReadOnly(checked);
        }
    });
    connect(ui->checkBox_set_editable,&QCheckBox::toggled,this,[=](bool checked){
        comboBox->setEditable(checked);
        // 设置可编辑时，更新 readonly 复选框状态
        if (comboBox->lineEdit()) {
            ui->checkBox_set_readonly->setChecked(comboBox->lineEdit()->isReadOnly());
        } else {
            // 如果不可编辑，则禁用 readonly 复选框
            ui->checkBox_set_readonly->setChecked(false);
        }
    });
}

ComboBoxDialog::~ComboBoxDialog()
{
    delete ui;
}
