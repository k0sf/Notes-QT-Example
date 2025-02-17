#ifndef JSCRIPT_H
#define JSCRIPT_H

#include <QObject>
#include <QDebug>
//#include <QVector>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>



struct AceEditorThemeStruct {
    QString caption;
    QString theme;
    bool isDark;
    QString name;

    QJsonObject toJson() const {
        QJsonObject obj;
        obj["caption"] = caption;
        obj["theme"] = theme;
        obj["isDark"] = isDark;
        obj["name"] = name;
        return obj;
    }
    void in_fromJson(const QVariant &data) {
        QJsonObject obj = QJsonObject::fromVariantMap(data.toMap());
        in_fromJson(obj);
    }
    void in_fromJson(const QJsonObject &obj) {
        caption = obj["caption"].toString();
        theme = obj["theme"].toString();
        isDark = obj["isDark"].toBool();
        name = obj["name"].toString();
    }
    static AceEditorThemeStruct fromJson(const QJsonObject &obj) {
        AceEditorThemeStruct s;
        s.caption = obj["caption"].toString();
        s.theme = obj["theme"].toString();
        s.isDark = obj["isDark"].toBool();
        s.name = obj["name"].toString();
        return s;
    }
    static AceEditorThemeStruct fromJson(const QVariant &data) {
        AceEditorThemeStruct s;
        QMap obj = data.toMap();
        s.caption = obj["caption"].toString();
        s.theme = obj["theme"].toString();
        s.isDark = obj["isDark"].toBool();
        s.name = obj["name"].toString();
        return s;
    }
    static AceEditorThemeStruct fromJson(const QVariantMap &obj) {
        AceEditorThemeStruct s;
        s.caption = obj.value("caption").toString();
        s.theme = obj.value("theme").toString();
        s.isDark = obj.value("isDark").toBool();
        s.name = obj.value("name").toString();
        return s;
    }
};

// {name: 'abap', caption: 'ABAP', mode: 'ace/mode/abap', extensions: 'abap', extRe: /^.*\.(abap)$/gi}
struct AceEditorModeStruct {
    QString caption;
    QString mode;
    QString name;

    QJsonObject toJson() const {
        QJsonObject obj;
        obj["caption"] = caption;
        obj["mode"] = mode;
        obj["name"] = name;
        return obj;
    }
    void in_fromJson(const QVariant &data) {
        QJsonObject obj = QJsonObject::fromVariantMap(data.toMap());
        in_fromJson(obj);
    }
    void in_fromJson(const QJsonObject &obj) {
        caption = obj["caption"].toString();
        mode = obj["mode"].toString();
        name = obj["name"].toString();
    }
    static AceEditorModeStruct fromJson(const QJsonObject &obj) {
        AceEditorModeStruct s;
        s.caption = obj["caption"].toString();
        s.mode = obj["mode"].toString();
        s.name = obj["name"].toString();
        return s;
    }
    static AceEditorModeStruct fromJson(const QVariant &data) {
        AceEditorModeStruct s;
        QMap obj = data.toMap();
        s.caption = obj["caption"].toString();
        s.mode = obj["mode"].toString();
        s.name = obj["name"].toString();
        return s;
    }
    static AceEditorModeStruct fromJson(const QVariantMap &obj) {
        AceEditorModeStruct s;
        s.caption = obj.value("caption").toString();
        s.mode = obj.value("mode").toString();
        s.name = obj.value("name").toString();
        return s;
    }
};

// 与js通讯交互
class jscript :public QObject
{
    Q_OBJECT
public:
    jscript();

public:
    QVector<AceEditorThemeStruct> theme_List;
    QVector<AceEditorModeStruct> mode_List;

public slots:
    void showThemeList(const QVariantList &themeList);
    void showModeList(const QVariantList &list);

private:

};


// {id: 'azcli', extensions: Array(1), aliases: Array(2), loader: ƒ}
struct MonacoEditorLangStruct {
    QString id;
    QList<QString> extensions;
    QList<QString> aliases;

    QJsonObject toJson() const {
        QJsonObject jsonObj;
        jsonObj["id"] = id;
        jsonObj["extensions"] = QJsonArray::fromStringList(extensions);
        jsonObj["aliases"] = QJsonArray::fromStringList(aliases);
        return jsonObj;
    }

    static MonacoEditorLangStruct fromJson(const QVariant &data) {
        MonacoEditorLangStruct lang;
        QMap obj = data.toMap();
        lang.id = obj["id"].toString();
        lang.extensions = obj["extensions"].toStringList();
        lang.aliases = obj["aliases"].toStringList();
        return lang;
    }
    static MonacoEditorLangStruct fromJson(const QJsonObject& jsonObj) {
        MonacoEditorLangStruct lang;
        lang.id = jsonObj["id"].toString();
        if(jsonObj["extensions"].isArray()){
            QJsonArray list = jsonObj["extensions"].toArray();
            for (const QJsonValueRef& v: list) {
                lang.extensions.append(v.toString());
            }
        }
        if(jsonObj["aliases"].isArray()){
            QJsonArray list = jsonObj["aliases"].toArray();
            for (const QJsonValueRef& v: list) {
                lang.aliases.append(v.toString());
            }
        }
        return lang;
    }
    static MonacoEditorLangStruct fromJson(const QByteArray& jsonData){
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        QJsonObject jsonObj = jsonDoc.object();
        return fromJson(jsonObj);
    }
    static MonacoEditorLangStruct fromJson(const QString& jsonText){
        return fromJson(jsonText.toUtf8());
    }
};

#endif // JSCRIPT_H
