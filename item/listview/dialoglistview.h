#ifndef DIALOGLISTVIEW_H
#define DIALOGLISTVIEW_H

#include <QDialog>
#include "customlistviewdelegate.h"


namespace Ui {
class DialogListView;
}

class DialogListView : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListView(QWidget *parent = nullptr);
    ~DialogListView();

private:
    Ui::DialogListView *ui;
};

#endif // DIALOGLISTVIEW_H
