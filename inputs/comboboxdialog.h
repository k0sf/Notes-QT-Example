#ifndef COMBOBOXDIALOG_H
#define COMBOBOXDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QMenu>
#include <QLayout>


class MenuComboBox : public QComboBox {
    Q_OBJECT

public:
    MenuComboBox(QWidget *parent = nullptr) : QComboBox(parent) {
        this->setEditable(false);  // 设置为不可编辑状态
    }

    // 绑定 QMenu 到 ComboBox
    void setMenu(QMenu *menu) {
        this->menu = menu;
        connect(this->menu,&QMenu::triggered,this,[=](QAction* action){
            int index = this->currentIndex();  // 获取当前索引
            if (index != -1) {
                this->setItemText(index, action->text());  // 设置当前项的文本
            } else {
                // 如果没有选中项，手动插入一项并设置文本
                this->addItem(action->text());
                this->setCurrentIndex(this->count() - 1);  // 选择新插入的项
            }
        });
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        Q_UNUSED(event);
        // 显示菜单
        if (menu) {
            menu->exec(mapToGlobal(QPoint(0, height())));
        }
    }

private slots:

private:
    QMenu *menu;
};


namespace Ui {
class ComboBoxDialog;
}

class ComboBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComboBoxDialog(QWidget *parent = nullptr);
    ~ComboBoxDialog();

private:
    Ui::ComboBoxDialog *ui;
};

#endif // COMBOBOXDIALOG_H
