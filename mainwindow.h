#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "progressbar.h"

// 窗口
#include "window/dialogwindowinteractive.h"

// 代码编辑器
#include "CodeEditor/AceEditorWindow.h"



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
    // 窗口交互
    DialogWindowInteractive* windowInteractive = new DialogWindowInteractive;

    // 代码编辑器
    AceEditorWindow* window_ace_editor = new AceEditorWindow;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
