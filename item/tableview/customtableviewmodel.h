#ifndef CUSTOMTABLEVIEWMODEL_H
#define CUSTOMTABLEVIEWMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QStyledItemDelegate>
#include <QProgressBar>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>

struct CustomStructTable {
    QString lineEdit; // 行编辑
    bool radioButton; // 单选框
    bool checkBox; // 复选框
    int progressBar; // 进度条
    QString pushButton;
    bool button;       // 按钮 (假设我们需要一个状态来表示按钮是否被点击过)
};

class CustomDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CustomDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {};

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        switch (index.column())
        {
        case 0: // Line edit
        {
            QLineEdit *editor = new QLineEdit(parent);
            return editor;
        }
        case 1: // Radio button
        {
            QRadioButton *editor = new QRadioButton(parent);
            return editor;
        }
        case 2: // Checkbox
        {
            QCheckBox *editor = new QCheckBox(parent);
            return editor;
        }
        case 3: // Progress bar
        {
            QProgressBar *editor = new QProgressBar(parent);
            editor->setRange(0, 100);
            return editor;
        }
        case 4: // Progress bar
        {
            QPushButton *editor = new QPushButton("hellojkjjk",parent);
            editor->setText("按钮");
            return editor;
        }
        default:
            return QStyledItemDelegate::createEditor(parent, option, index);
        }
    };

    void setEditorData(QWidget *editor, const QModelIndex &index) const override
    {
        switch (index.column())
        {
        case 0:
        {
            QString text = index.model()->data(index, Qt::EditRole).toString();
            QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
            lineEdit->setText(text);
            break;
        }
        case 1:
        {
            bool checked = index.model()->data(index, Qt::EditRole).toBool();
            QRadioButton *radioButton = qobject_cast<QRadioButton *>(editor);
            radioButton->setChecked(checked);
            break;
        }
        case 2:
        {
            bool checked = index.model()->data(index, Qt::EditRole).toBool();
            QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
            checkBox->setChecked(checked);
            break;
        }
        case 3:
        {
            int value = index.model()->data(index, Qt::EditRole).toInt();
            QProgressBar *progressBar = qobject_cast<QProgressBar *>(editor);
            progressBar->setValue(value);
            break;
        }
        case 4:
        {
            // QString value = index.model()->data(index, Qt::EditRole).toString();
            // QPushButton *pushButton = qobject_cast<QPushButton *>(editor);
            // pushButton->setText(value);
            break;
        }
        default:
            QStyledItemDelegate::setEditorData(editor, index);
            break;
        }
    };

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override
    {
        switch (index.column())
        {
        case 0:
        {
            QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
            model->setData(index, lineEdit->text(), Qt::EditRole);
            break;
        }
        case 1:
        {
            QRadioButton *radioButton = qobject_cast<QRadioButton *>(editor);
            model->setData(index, radioButton->isChecked(), Qt::EditRole);
            break;
        }
        case 2:
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
            model->setData(index, checkBox->isChecked(), Qt::EditRole);
            break;
        }
        case 3:
        {
            QProgressBar *progressBar = qobject_cast<QProgressBar *>(editor);
            model->setData(index, progressBar->value(), Qt::EditRole);
            break;
        }
        case 4:
        {
            // QPushButton *pushButton = qobject_cast<QPushButton *>(editor);
            // model->setData(index, pushButton->text(), Qt::EditRole);
            break;
        }
        default:
            QStyledItemDelegate::setModelData(editor, model, index);
            break;
        }
    };

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        Q_UNUSED(index);
        editor->setGeometry(option.rect);
    };
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        switch (index.column())
        {
        case 1: {
            bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
            QStyleOptionButton radioButtonOption;
            radioButtonOption.state = checked ? QStyle::State_On : QStyle::State_Off;
            radioButtonOption.rect = option.rect;
            QApplication::style()->drawControl(QStyle::CE_RadioButton, &radioButtonOption, painter);
            break;
        }
        case 2: {
            bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
            QStyleOptionButton checkBoxOption;
            checkBoxOption.state = checked ? QStyle::State_On : QStyle::State_Off;
            checkBoxOption.rect = option.rect;
            QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkBoxOption, painter);
            break;
        }
        case 3: {
            int progress = index.model()->data(index, Qt::DisplayRole).toInt();
            QStyleOptionProgressBar progressBarOption;
            progressBarOption.rect = option.rect;
            progressBarOption.minimum = 0;
            progressBarOption.maximum = 100;
            progressBarOption.progress = progress;
            QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);
            break;
        }
        case 4: {
            QString text = index.model()->data(index, Qt::DisplayRole).toString();
            QStyleOptionButton buttonOption;
            buttonOption.rect = option.rect;
            // buttonOption.rect = option.rect.adjusted(4, 4, -(option.rect.width() / 2 + 4) , -4);
            buttonOption.state = QStyle::State_Enabled;  // Ensure the button is enabled
            buttonOption.text = text;
            QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption, painter);
            break;
        }
        default:
            QStyledItemDelegate::paint(painter, option, index);
            break;
        }
    };
};

class CustomTableViewModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CustomTableViewModel(QObject *parent = nullptr){Q_UNUSED(parent);};

    // Header(头部):
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        // FIXME: Implement me!
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            // if(section < m_header.size()){
            //     return m_header.at(section);
            // }
            return section < m_header.size() ?m_header.at(section):QVariant();
            // switch (section) {
            // case 0: return QString("id");
            // case 1: return QString("name");
            // case 2: return QString("desc");
            // case 3: return QString("status");
            // default: return QVariant();
            // }
        }

        return QVariant();
    };

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override {
        if (value != headerData(section, orientation, role)) {
            // FIXME: Implement me!
            emit headerDataChanged(orientation, section, section);
            return true;
        }
        return false;
    };

    // Basic functionality(基本功能):
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        if (parent.isValid())
            return 0;

        // FIXME: Implement me!
        return m_model.size();
    };
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        if (parent.isValid())
            return 0;

        // FIXME: Implement me!
        return m_header.size();
    };

    // // Fetch data dynamically(动态获取数据):
    // bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

    // bool canFetchMore(const QModelIndex &parent) const override;
    // void fetchMore(const QModelIndex &parent) override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || index.row() >= m_model.size())
            return QVariant();

        // FIXME: Implement me!
        const CustomStructTable &st = m_model.at(index.row());

        if (role == Qt::DisplayRole) {
            switch (index.column()) {
            case 0: return st.lineEdit;
            case 1: return st.radioButton;
            case 2: return st.checkBox;
            case 3: return st.progressBar;
            case 4: return st.pushButton;
            default: return QVariant();
            }
        }
        return QVariant();
    };

    // Editable(可编辑):
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override {
        if (data(index, role) != value) {
            // FIXME: Implement me!
            CustomStructTable &st = m_model[index.row()];

            switch (index.column()) {
            case 0: st.lineEdit = value.toString(); break;
            case 1: st.radioButton = value.toBool(); break;
            case 2: st.checkBox = value.toBool(); break;
            case 3: st.progressBar = value.toInt(); break;
            case 4: st.pushButton = value.toString(); break;
            default: return false;
            }
            emit dataChanged(index, index, {role});
            return true;
        }
        return false;
    };

    Qt::ItemFlags flags(const QModelIndex &index) const override {
        if (!index.isValid())
            return Qt::NoItemFlags;

        // 设置第1列可编辑
        if (index.column() == 1)
            return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;

        return QAbstractItemModel::flags(index); // FIXME: Implement me!
    };

    // // Add data(添加数据):
    // bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    // bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // // Remove data(移除数据):
    // bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    // bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // 设置表头
    void setHeaderLabels(QStringList labels){
        if(labels.size() <= 0){ return; }
        m_header = labels;
    };
    // 添加数据
    void add(const CustomStructTable &st){
        beginInsertRows(QModelIndex(), m_model.size(), m_model.size());
        m_model.append(st);
        endInsertRows();
    };

private:
    QStringList m_header = {"编辑框","单选框","复选框","进度条","按钮"};
    QVector<CustomStructTable> m_model;
};

#endif // CUSTOMTABLEVIEWMODEL_H
