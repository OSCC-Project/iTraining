#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <qpainter.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), grid_map(0, 0)
{
    ui->setupUi(this);
    ui->rb_obstacle->setChecked(1);

    ui->hs_penalty->setMaximum(1000);

    ui->w_path->installEventFilter(this);
    ui->w_path->setStyleSheet("background:transparent;border:0px");
    ui->w_path->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == ui->w_path && event->type() == QEvent::Paint) {
        if (path.size() > 0) {
            QPainter painter(ui->w_path);
            painter.setPen(QPen(QColor(180, 180, 255), 4));

            int offset = grid_size / 2;

            for (int i = 1; i < path.size(); i++) {
                int start_x = path[i-1]->y() * grid_size + offset;
                int start_y = path[i-1]->x() * grid_size + offset;
                int end_x = path[i]->y() * grid_size + offset;
                int end_y = path[i]->x() * grid_size + offset;
                painter.drawLine(start_x, start_y, end_x, end_y);
            }

            // qDebug() << "draw!";
            return true;
        }
        return false;
    } else {
        return QMainWindow::eventFilter(watched, event);
    }
}

//void MainWindow::paintEvent(QPaintEvent *e) {
//    if (path.size() > 0) {
//        QPainter painter(ui->w_path);
//        painter.setPen(QPen(Qt::blue, 4));

//        for (int i = 1; i < path.size(); i++) {
//            int start_x = path[i-1]->y() * grid_size;
//            int start_y = path[i-1]->x() * grid_size;
//            int end_x = path[i]->y() * grid_size;
//            int end_y = path[i]->x() * grid_size;
//            painter.drawLine(start_x, start_y, end_x, end_y);
//        }
//    }
//}

void MainWindow::init() {
    starting_position = { -1, -1 };
    ending_position = { -1, -1 };

    path = {};
}

void MainWindow::test_if_have_a_path() {
    if (starting_position.x() != -1 && ending_position.x() != -1) {
        path = astar::PathFinder::findPath(grid_map, starting_position, ending_position);
        // qDebug() << "find a path! length:" << path.size();
        update();
    }
}

void MainWindow::set_button_style(int x, int y) {
    const QString obstacle_color = "brown";
    const QString starting_position_color = "pink";
    const QString ending_position_color = "lightgreen";

    QStringList style_list;

    int penalty = 0;
    double walk_cost = grid_map[x][y].get_walk_cost();
    if (walk_cost > 0) {
        penalty = walk_cost * 100.0;
    }

    if (starting_position == point::Point2i{ x, y }) {
        style_list.append("background-color:" + starting_position_color);
    } else if (ending_position == point::Point2i{ x, y }) {
        style_list.append("background-color:" + ending_position_color);
    } else if (grid_map[x][y].isWalkable()) {
        QString color = QString::number(255 - penalty / 1000.0 * 255);

        if (penalty < 200) {
            style_list.append("color:black");
        } else {
            style_list.append("color:white");
        }
        style_list.append("background-color:rgb("+ color + "," + color + "," + color + ")");
    } else {
        style_list.append("background-color:" + obstacle_color);
    }

    if (grid_map[x][y].isWalkable()) {
        map[x][y]->setText(QString::number(penalty));
    } else {
        map[x][y]->setText("x");
    }

    map[x][y]->setStyleSheet(style_list.join(";"));
}

void MainWindow::set_grid_map(int x, int y) {
    if (ui->rb_roadway->isChecked()) {
        int penalty = ui->hs_penalty->sliderPosition();
        grid_map[x][y].set_walk_cost(penalty / 100.0);
    } else if (ui->rb_obstacle->isChecked()) {
        grid_map[x][y].set_walk_cost(INFINITY);
    } else if (ui->rb_startingposition->isChecked()) {
        if (grid_map[x][y].isWalkable() &&
            !(ending_position.x() == x && ending_position.y() == y)) {
            point::Point2i original_starting_position = starting_position;
            starting_position = { x, y };
            if (original_starting_position.x() != -1) {
                set_button_style(original_starting_position.x(), original_starting_position.y());
            }
        }
    } else if (ui->rb_endingposition->isChecked()) {
        if (grid_map[x][y].isWalkable() &&
            !(starting_position.x() == x && starting_position.y() == y)) {
            point::Point2i original_ending_position = ending_position;
            ending_position = { x, y };
            if (original_ending_position.x() != -1) {
                set_button_style(original_ending_position.x(), original_ending_position.y());
            }
        }
    }
    set_button_style(x, y);

    test_if_have_a_path();
}

void MainWindow::on_pb_confirm_clicked()
{
    init();

    int map_row = ui->le_row->text().toInt();
    int map_column  = ui->le_column->text().toInt();
    // qDebug() << map_row << map_column;
    int map_width = ui->gb_map->width();
    int map_height = ui->gb_map->height();
    // qDebug() << map_width << map_height;

    int button_width = (map_width - 6) / map_column;
    int button_height = (map_height - 23) / map_row;

    grid_size = std::min(button_width, button_height);
    QStringList style_list;
    style_list.append("color:black");
    style_list.append("background-color:white");
    style_list.append("border-style:outset");
//    style_list.append("border-width:1px");

    grid_map = gridmap::Map<astar::Node>(map_row, map_column);
    for (auto &line : map) {
        for (auto &button : line) {
            button->deleteLater();
        }
    }
    map = {};

    if (map.size() == 0) {
        for (int i = 0; i < map_row; ++i) {
            map.push_back({});
            for (int j = 0; j < map_column; ++j) {
                QPushButton * button = new QPushButton(ui->gb_map);
                button->setStyleSheet(style_list.join(";"));
                button->resize(grid_size, grid_size);
                button->move(grid_size * j + 3, grid_size * i + 20);
                button->setText("0");

                connect(button, &QPushButton::pressed, [=]() {
                    set_grid_map(i, j);
                });

                button->show();
                map[i].push_back(button);
            }
        }
    }

    ui->w_path->raise();
}


void MainWindow::on_le_row_returnPressed()
{
    on_pb_confirm_clicked();
}


void MainWindow::on_le_column_returnPressed()
{
    on_pb_confirm_clicked();
}

