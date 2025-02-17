#ifndef CUSTOMLISTVIEWDELEGATE_H
#define CUSTOMLISTVIEWDELEGATE_H

#include <QObject>
#include <QWidget>

// class CustomListViewDelegate
// {
//     Q_OBJECT
// public:
//     CustomListViewDelegate();
// };

#include <QStyledItemDelegate>
#include <QPainter>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

class CustomListViewItemWidget : public QWidget {
    Q_OBJECT
public:
    CustomListViewItemWidget(const QString &text, int progress, QWidget *parent = nullptr) : QWidget(parent) {
        QHBoxLayout *mainLayout = new QHBoxLayout(this);
        mainLayout->setContentsMargins(1, 1, 1, 1);

        QVBoxLayout *leftLayout = new QVBoxLayout;
        leftLayout->setSpacing(1);

        QLabel *label = new QLabel(text, this);
        QProgressBar *progressBar = new QProgressBar(this);
        progressBar->setValue(progress);

        QHBoxLayout *rightLayout = new QHBoxLayout;
        QPushButton *pauseButton = new QPushButton("暂停/启动", this);
        QPushButton *cancelButton = new QPushButton("取消", this);

        leftLayout->addWidget(label);
        leftLayout->addWidget(progressBar);

        rightLayout->addWidget(pauseButton);
        rightLayout->addWidget(cancelButton);

        mainLayout->addLayout(leftLayout);
        mainLayout->addLayout(rightLayout);
        connect(pauseButton, &QPushButton::clicked, this, &CustomListViewItemWidget::pauseButtonClicked);
        connect(cancelButton, &QPushButton::clicked, this, &CustomListViewItemWidget::cancelButtonClicked);
    }

signals:
    void pauseButtonClicked();
    void cancelButtonClicked();
};

class CustomListViewDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    CustomListViewDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {};

    // QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
    //     QString text = index.data(Qt::DisplayRole).toString();
    //     int progress = index.data(Qt::UserRole + 1).toInt();
    //     return new CustomListViewItemWidget(text, progress, parent);
    // }

    // void setEditorData(QWidget *editor, const QModelIndex &index) const override {
    //     if (auto *widget = qobject_cast<CustomListViewItemWidget*>(editor)) {
    //         int progress = index.data(Qt::UserRole + 1).toInt();
    //         widget->findChild<QProgressBar*>()->setValue(progress);
    //     }
    // }

    // void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
    //     editor->setGeometry(option.rect);
    // }

    // QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override {
    //     return QSize(400, 50);
    // }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QString text = index.data(Qt::DisplayRole).toString();
        int progress = index.data(Qt::UserRole + 1).toInt();

        // Create CustomItemWidget and render it to a pixmap
        CustomListViewItemWidget widget(text, progress);
        widget.resize(option.rect.size());

        QPixmap pixmap(widget.size());
        widget.render(&pixmap);

        painter->drawPixmap(option.rect, pixmap);
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_UNUSED(index);Q_UNUSED(option);
        return QSize(400, 50);
    }
};

#endif // CUSTOMLISTVIEWDELEGATE_H
