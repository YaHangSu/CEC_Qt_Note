#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QHeaderView>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableWidget = new QTableWidget(this);
    tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(tableWidget, &QTableWidget::customContextMenuRequested, this, &MainWindow::showContextMenu);

    // 添加一些示例数据
    tableWidget->setRowCount(5);
    tableWidget->setColumnCount(2);
    tableWidget->setHorizontalHeaderLabels({"列1", "列2"});
    tableWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 2; ++col)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString("行%1 列%2").arg(row).arg(col));
            tableWidget->setItem(row, col, item);
        }
    }

    setCentralWidget(tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("右键菜单"), this);
    QAction deleteAction("删除选定行", this);
    connect(&deleteAction, &QAction::triggered, this, &MainWindow::deleteSelectedRows);
    contextMenu.addAction(&deleteAction);
    contextMenu.exec(tableWidget->mapToGlobal(pos));
}

void MainWindow::deleteSelectedRows()
{
    QList<QTableWidgetItem *> selectedItems = tableWidget->selectedItems();
    QList<int> rowsToDelete;

    for (QTableWidgetItem *item : selectedItems)
    {
        int row = item->row();
        if (!rowsToDelete.contains(row))
        {
            rowsToDelete.append(row);
        }
    }

    std::sort(rowsToDelete.begin(), rowsToDelete.end(), std::greater<int>());

    for (int row : rowsToDelete)
    {
        tableWidget->removeRow(row);
    }
}
