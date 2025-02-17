#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "progressbar.h"

// 基本控件
#include "inputs/comboboxdialog.h"

// 窗口
#include "window/dialogwindowinteractive.h"

// 代码编辑器
#include "CodeEditor/AceEditorWindow.h"
#include "CodeEditor/MonacoEditorWindow.h"


#include "item/listwidget/dialoglistwidget.h"

// 项目 列表视图
#include "item/listview/dialoglistview.h"

// 项目 表格视图
#include "item/tableview/dialogtableview.h"



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

    // 基本控件
    ComboBoxDialog* combobox = new ComboBoxDialog();

    // 窗口交互
    DialogWindowInteractive* windowInteractive = new DialogWindowInteractive;

    // 代码编辑器
    AceEditorWindow* window_ace_editor = new AceEditorWindow;
    MonacoEditorWindow* window_monaco_editor = new MonacoEditorWindow;

    DialogListWidget* window_listwidget = new DialogListWidget();
    DialogListView* window_listview = new DialogListView;
    // 项目表格视图
    DialogTableView* window_tableview = new DialogTableView;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
