#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "progressbar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    progressbar* pbarWindow = new progressbar(); // 进度条

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
