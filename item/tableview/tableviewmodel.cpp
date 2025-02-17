#include "tableviewmodel.h"

TableViewModel::TableViewModel(QObject *parent)
    : QAbstractTableModel(parent)
{}

QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
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
}

bool TableViewModel::setHeaderData(int section,
                                   Qt::Orientation orientation,
                                   const QVariant &value,
                                   int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int TableViewModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_model.size();
}

int TableViewModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 4;
}

// bool TableViewModel::hasChildren(const QModelIndex &parent) const
// {
//     // FIXME: Implement me!
// }

// bool TableViewModel::canFetchMore(const QModelIndex &parent) const
// {
//     // FIXME: Implement me!
//     return false;
// }

// void TableViewModel::fetchMore(const QModelIndex &parent)
// {
//     // FIXME: Implement me!
// }

QVariant TableViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_model.size())
        return QVariant();

    // FIXME: Implement me!
    const StructTable &st = m_model.at(index.row());

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return st.id;
        case 1: return st.name;
        case 2: return st.desc;
        case 3: return st.status;
            // case 3: return st.connectTime.toString(Qt::ISODate);
        default: return QVariant();
        }
    }
    return QVariant();
}

bool TableViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        StructTable &st = m_model[index.row()];

        switch (index.column()) {
        case 0: st.id = value.toInt(); break;
        case 1: st.name = value.toString(); break;
        case 2: st.desc = value.toString(); break;
        case 3: st.status = value.toBool(); break;
        default: return false;
        }
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags TableViewModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    // 设置第1列可编辑
    if (index.column() == 1)
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;

    return QAbstractItemModel::flags(index); // FIXME: Implement me!
}

// bool TableViewModel::insertRows(int row, int count, const QModelIndex &parent)
// {
//     beginInsertRows(parent, row, row + count - 1);
//     // FIXME: Implement me!
//     endInsertRows();
//     return true;
// }

// bool TableViewModel::insertColumns(int column, int count, const QModelIndex &parent)
// {
//     beginInsertColumns(parent, column, column + count - 1);
//     // FIXME: Implement me!
//     endInsertColumns();
//     return true;
// }

// bool TableViewModel::removeRows(int row, int count, const QModelIndex &parent)
// {
//     beginRemoveRows(parent, row, row + count - 1);
//     // FIXME: Implement me!
//     endRemoveRows();
//     return true;
// }

// bool TableViewModel::removeColumns(int column, int count, const QModelIndex &parent)
// {
//     beginRemoveColumns(parent, column, column + count - 1);
//     // FIXME: Implement me!
//     endRemoveColumns();
//     return true;
// }

void TableViewModel::setHeaderLabels(QStringList labels)
{
    if(labels.size() <= 0){ return; }
    m_header = labels;
}
void TableViewModel::add(const StructTable &st)
{
    beginInsertRows(QModelIndex(), m_model.size(), m_model.size());
    m_model.append(st);
    endInsertRows();
}
