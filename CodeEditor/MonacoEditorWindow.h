#ifndef MONACOEDITORWINDOW_H
#define MONACOEDITORWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QWebEngineView>
#include <QWebChannel>
#include <QWebEngineSettings>

#include "CodeEditor/jscript.h"

class MonacoObj : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString code READ code WRITE setCode NOTIFY codeChanged)
    Q_PROPERTY(QString theme READ theme WRITE setTheme NOTIFY themeChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)

public:
    MonacoObj() {}

public:
    QVector<QString> themes;
    QVector<MonacoEditorLangStruct> langs;

    QString code() const { return m_code; }
    void setCode(const QString &newContent) {
        if (m_code != newContent) {
            m_code = newContent;
            emit codeChanged(m_code);
        }
    }

    QString theme() const { return m_theme; }
    void setTheme(const QString &newTheme) {
        if (m_theme != newTheme) {
            m_theme = newTheme;
            emit themeChanged(m_theme);
        }
    }

    QString language() const { return m_language; }
    void setLanguage(const QString &newLanguage) {
        if (m_language != newLanguage) {
            m_language = newLanguage;
            emit languageChanged(m_language);
        }
    }

signals:
    void codeChanged(const QString &newCode);
    void themeChanged(const QString &newTheme);
    void languageChanged(const QString &newLanguage);

public slots:
    void setLangs(const QVariant &result){
        QVector<MonacoEditorLangStruct> lang_list;
        QList<QVariant> list = result.toList();
        for (const QVariant& lang : list) {
            MonacoEditorLangStruct l = MonacoEditorLangStruct::fromJson(lang);
            lang_list.push_back(l);
        }
        langs = lang_list;
    };

private:
    QString m_code;
    QString m_theme;
    QString m_language;
};

namespace Ui {
class MonacoEditorWindow;
}

class MonacoEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonacoEditorWindow(QWidget *parent = nullptr);
    ~MonacoEditorWindow();

private:
    Ui::MonacoEditorWindow *ui;
};

#endif // MONACOEDITORWINDOW_H
