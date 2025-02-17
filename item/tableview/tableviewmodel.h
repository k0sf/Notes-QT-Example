#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H

#include <QAbstractTableModel>
// #include <QStyledItemDelegate>
// #include <QProgressBar>
// #include <QCheckBox>
// #include <QRadioButton>
// #include <QLineEdit>
#include <QDateTime>

struct StructTable {
    int id;
    QString name;
    QString desc;
    bool status;
    // QDateTime time;
};




class TableViewModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TableViewModel(QObject *parent = nullptr);

    // Header(头部):
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality(基本功能):
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // // Fetch data dynamically(动态获取数据):
    // bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

    // bool canFetchMore(const QModelIndex &parent) const override;
    // void fetchMore(const QModelIndex &parent) override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable(可编辑):
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    // // Add data(添加数据):
    // bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    // bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // // Remove data(移除数据):
    // bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    // bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // 设置表头
    void setHeaderLabels(QStringList labels);
    // 添加数据
    void add(const StructTable &st);

private:
    QStringList m_header = {"id","name","desc","status"};
    QVector<StructTable> m_model;
};






#endif // TABLEVIEWMODEL_H
