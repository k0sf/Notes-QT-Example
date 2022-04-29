#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QMainWindow>
#include <QtGlobal>

namespace Ui {
class progressbar;
}

class progressbar : public QMainWindow
{
    Q_OBJECT

public:
    explicit progressbar(QWidget *parent = nullptr);
    ~progressbar();

private:
    Ui::progressbar *ui;
};

#endif // PROGRESSBAR_H
