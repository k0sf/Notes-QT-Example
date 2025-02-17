#include "MonacoEditorWindow.h"
#include "ui_MonacoEditorWindow.h"

MonacoEditorWindow::MonacoEditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MonacoEditorWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Monaco Editor in Qt");

    // 创建 QWebEngineView
    QWebEngineView *webView = new QWebEngineView(this);

    // 创建 QWebChannel 并注册 C++ 对象
    QWebChannel *webChannel = new QWebChannel(this);
    MonacoObj *webobj = new MonacoObj();
    webChannel->registerObject("webobj", webobj);
    webView->page()->setWebChannel(webChannel);
    webView->setUrl(QUrl("qrc:/monaco/index.qt.html"));
    connect(webobj,&MonacoObj::languageChanged,[=](QString id){
        // qInfo()<<"改变语言id"<<id;
        if(ui->comboBox_lang->count() <= 0){
            QStringList langs;
            for (const MonacoEditorLangStruct& lang : webobj->langs) {
                QString name;
                if(lang.aliases.size() > 0){
                    name = lang.aliases[0];
                }else{
                    name = lang.id;
                }
                langs.append(name);
            }
            ui->comboBox_lang->addItems(langs);
        }

        for (const MonacoEditorLangStruct& lang : webobj->langs) {
            if(lang.id == id){
                if(lang.aliases.size() > 0){
                    // qInfo()<<"选择框语言"<<lang.aliases[0];
                    ui->comboBox_lang->setCurrentText(lang.aliases[0]);
                    break;
                }
                ui->comboBox_lang->setCurrentText(lang.id);
                break;
            }
        }
    });
    connect(webobj,&MonacoObj::themeChanged,[=](const QString& theme){
        ui->comboBox_themes->setCurrentText(theme);
    });
    // webView->setUrl(QUrl("http://127.0.0.1:9100/index_qt.html"));
    // webView->settings()->setAttribute(QWebEngineSettings::DeveloperExtrasEnabled, true);
    // // 加载 Monaco Editor
    // webView->setHtml(R"(
    //         <!DOCTYPE html>
    //         <html>
    //         <head>
    //             <meta charset="UTF-8">
    //             <script src="https://cdnjs.cloudflare.com/ajax/libs/monaco-editor/0.52.2/min/vs/loader.min.js"></script>
    //         </head>
    //         <style>
    //             #container {
    //                 height: 100%;
    //                 width: 100%;
    //                 margin: 0;
    //                 position: absolute;
    //                 top: 0;
    //                 bottom: 0;
    //                 left: 0;
    //                 right: 0;
    //             }
    //         </style>
    //         <body>
    //             <div id="container"></div>
    //             <script>
    //                 require.config({ paths: { 'vs': 'https://cdnjs.cloudflare.com/ajax/libs/monaco-editor/0.52.2/min/vs' }});
    //                 require(['vs/editor/editor.main'], function() {
    //                     var editor = monaco.editor.create(document.getElementById('container'), {
    //                         value: "// Hello, Monaco Editor!\nint main() {\n    return 0;\n}",
    //                         language: 'cpp',
    //                         theme: 'vs-dark'
    //                     });

    //                     // 监听内容变化
    //                     editor.onDidChangeModelContent(function(event) {
    //                         console.log('Content changed:', editor.getValue());
    //                     });
    //                     // 监听窗口大小变化，调整编辑器布局
    //                     window.addEventListener('resize', function() {
    //                         editor.layout();
    //                     });

    //                     // 设置语言的函数
    //                     function setLanguage(language) {
    //                         const model = editor.getModel(); // 获取当前编辑器模型
    //                         monaco.editor.setModelLanguage(model, language); // 设置语言
    //                     }

    //                 });

    //             </script>
    //         </body>
    //         </html>
    //     )");
    // 主题 themes: 'vs' (default), 'vs-dark', 'hc-black', 'hc-light'
    ui->comboBox_themes->addItems({"vs", "vs-dark", "hc-black", "hc-light" });
    connect(webView,&QWebEngineView::loadFinished,[=](bool ok){
        if(ok){
            // webView->page()->runJavaScript("monaco.languages.getLanguages();", [=](const QVariant &result) {
            //     QList<QVariant> list = result.toList();
            //     QStringList langs;
            //     for (const QVariant& lang : list) {
            //         MonacoEditorLangStruct l = MonacoEditorLangStruct::fromJson(lang);
            //         QString name;
            //         if(l.aliases.size() > 0){
            //             name = l.aliases[0];
            //         }else{
            //             name = l.id;
            //         }
            //         langs.append(name);
            //     }
            //     ui->comboBox_lang->addItems(langs);
            //     // qDebug() << "x Supported Languages:" << result.toList();
            // });
            // QStringList langs;
            // for (const MonacoEditorLangStruct& lang : webobj->langs) {
            //     QString name;
            //     if(lang.aliases.size() > 0){
            //         name = lang.aliases[0];
            //     }else{
            //         name = lang.id;
            //     }
            //     langs.append(name);
            // }
            // ui->comboBox_lang->addItems(langs);

            // editor.getValue(); // 获取代码
            // editor.setValue(code); // 设置代码内容
            // editor.getModel().getLanguageId(); // 获取当前语言ID
            // monaco.editor.setModelLanguage(editor.getModel(), language); // 设置语言
            // editor._themeService._theme.themeName; // 当前主题
            // monaco.editor.setTheme('mytheme'); // 设置主题
        }
    });
    connect(ui->comboBox_lang,&QComboBox::currentTextChanged,[=](QString text){
        for (const MonacoEditorLangStruct& lang : webobj->langs){
            QString id;
            if(lang.aliases.size() > 0){
                if(lang.aliases[0] == text){
                    id = lang.id;
                }
            }else if(lang.id == text){
                id = lang.id;
            }
            if(!id.isEmpty()){
                webobj->setLanguage(id);
                break;
            }
        }
    });
    connect(ui->comboBox_themes,&QComboBox::currentTextChanged,[=](QString text){
        webobj->setTheme(text);
    });

    ui->centralwidget->layout()->addWidget(webView);


}

MonacoEditorWindow::~MonacoEditorWindow()
{
    delete ui;
}
