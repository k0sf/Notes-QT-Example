#include "AceEditorWindow.h"
#include "ui_AceEditorWindow.h"



AceEditorWindow::AceEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AceEditorWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Ace 编辑器"); // AceEditorWindow

    // 测试编辑器
    // 创建QWebEngineView对象
    QWebEngineView *view = new QWebEngineView();
    view->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled,true);
    // 加载Ace编辑器
    view->setUrl(QUrl("qrc:/code_editor/ace/test.html")); // 从资源加载
    // 从本地加载
//    view->load(QUrl::fromLocalFile("/Users/yang/Documents/k0sf/Notes-QT-Example/code_editor/ace/test.html"));
    // 创建QWebChannel对象
    QWebChannel *channel = new QWebChannel(view->page());

    // 注册C++对象
//    QObject *obj = new QObject(this);
    jscript *obj = new jscript();
    channel->registerObject("cppObj", obj);

    // 将QWebChannel对象绑定到Ace编辑器的JavaScript环境中
    view->page()->setWebChannel(channel);
    connect(view,&QWebEngineView::loadFinished,[=]{
        qDebug()<< "加载完成";

        // 主题
        QStringList names;
        for (auto x : obj->theme_List) {
            names.append(x.caption);
        }
        if(names.size() > 0){
            ui->comboBox_themes->addItems(names);
            ui->comboBox_themes->setCurrentText("Monokai");// 默认主题
        }
        // 语言
        QStringList langs;
        for (auto x : obj->mode_List) {
            langs.append(x.caption);
        }
        if(langs.size() > 0){
            ui->comboBox_lang->addItems(langs);
            ui->comboBox_lang->setCurrentText("HTML");// 默认语言
        }

    });
    connect(ui->comboBox_lang,&QComboBox::currentTextChanged,[=](QString text){
        for (auto x : obj->mode_List) {
            if(text == x.caption){
                view->page()->runJavaScript(QString("setMode('%1')").arg(x.mode));
                break;
            }
        }
    });
    connect(ui->comboBox_themes,&QComboBox::currentTextChanged,[=](QString text){
        for (auto x : obj->theme_List) {
            if(text == x.caption){
                view->page()->runJavaScript(QString("setTheme('%1')").arg(x.theme));
                break;
            }
        }
    });

    ui->centralwidget->layout()->addWidget(view);
}

AceEditorWindow::~AceEditorWindow()
{
    delete ui;
}
