#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "gridmap.h"
#include "astar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
//    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_pb_confirm_clicked();
    void set_grid_map(int x, int y);

    void on_le_row_returnPressed();

    void on_le_column_returnPressed();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<QPushButton *>> map;
    gridmap::Map<astar::Node> grid_map;
    point::Point2i starting_position;
    point::Point2i ending_position;
    std::vector<astar::Node *> path;
    int grid_size;

    void init();
    void test_if_have_a_path();
    void set_button_style(int x, int y);
};
#endif // MAINWINDOW_H
