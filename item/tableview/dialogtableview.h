#ifndef DIALOGTABLEVIEW_H
#define DIALOGTABLEVIEW_H

#include <QDialog>
#include "tableviewmodel.h"
#include "customtableviewmodel.h"

namespace Ui {
class DialogTableView;
}

class DialogTableView : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTableView(QWidget *parent = nullptr);
    ~DialogTableView();

private:
    Ui::DialogTableView *ui;

    // 模型
    TableViewModel* model = new TableViewModel();

    CustomTableViewModel* cmodel = new CustomTableViewModel();
    CustomDelegate* cd = new CustomDelegate();
};

#endif // DIALOGTABLEVIEW_H
