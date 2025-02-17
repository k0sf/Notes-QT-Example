#ifndef DIALOGLISTWIDGET_H
#define DIALOGLISTWIDGET_H

#include <QDialog>

namespace Ui {
class DialogListWidget;
}

class DialogListWidget : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListWidget(QWidget *parent = nullptr);
    ~DialogListWidget();

private:
    Ui::DialogListWidget *ui;
};

#endif // DIALOGLISTWIDGET_H
