#include "jscript.h"

jscript::jscript()
{

}



void jscript::showThemeList(const QVariantList &themeList) {
//    qDebug() << "Theme List:";
    for (const QVariant &theme : themeList) {
        QVariantMap themeMap = theme.toMap();
        AceEditorThemeStruct data = AceEditorThemeStruct::fromJson(themeMap);
        theme_List.push_back(data);
//        themeList.
//        qDebug() << "主题"<<theme; // {caption: 'SQL Server', theme: 'ace/theme/sqlserver', isDark: false, name: 'sqlserver'}
//        QVariantMap themeMap = theme.toMap();
//        data.caption = themeMap.value("caption").toString();
//        data.theme = themeMap.value("theme").toString();
//        data.isDark = themeMap.value("isDark").toBool();
//        data.name = themeMap.value("name").toString();

//        themeList.push_back(data);
//        theme
//        qDebug() <<"主题"<< caption<<path << isDark<<name;
//        qDebug() <<"主题"<<theme  << "解析" << "caption",caption,"|","path",path ,"|","isDark",isDark,"|","name",name;
    }
}

void jscript::showModeList(const QVariantList &list)
{
    for (const QVariant &x : list) {
        QVariantMap themeMap = x.toMap();
        AceEditorModeStruct data = AceEditorModeStruct::fromJson(themeMap);
        mode_List.push_back(data);
    }
}
