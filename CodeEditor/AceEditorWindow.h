#ifndef ACEEDITORWINDOW_H
#define ACEEDITORWINDOW_H

#include <QMainWindow>

#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QWebChannel>

#include "CodeEditor/jscript.h"

namespace Ui {
class AceEditorWindow;
}

class AceEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AceEditorWindow(QWidget *parent = nullptr);
    ~AceEditorWindow();


private:
    Ui::AceEditorWindow *ui;
};



#endif // ACEEDITORWINDOW_H
