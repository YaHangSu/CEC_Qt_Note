#ifndef MAINWINDOW_H
#define MAINWINDOW_H
// QTableWidget 右键批量删除 -YTH项目-
#include <QTableWidget>
#include <QMenu>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showContextMenu(const QPoint &pos);
    void deleteSelectedRows();

private:
    QTableWidget *tableWidget;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
