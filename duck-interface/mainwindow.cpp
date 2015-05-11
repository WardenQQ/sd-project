#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(0, 0, LENGTH, HEIGHT);

    random_map(&(this->map), 4, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    this->displayMap();
}

void MainWindow::displayMap()
{
    QPainter painter(this);

    //painter.drawLine(1,1,100,100);

    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::darkBlue, Qt::SolidPattern));

    int r, x, y;
    for (int i = 0; i < map.nbr_of_blocks; i++) {
        r = map.blocks[i].radius;
        x = map.blocks[i].x - r;
        y = map.blocks[i].y - r;
        painter.drawEllipse(x, y, r, r);
    }

    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    for (int i = 0; i < map.nbr_of_goals; i++) {
        r = map.goals[i].radius;
        x = map.goals[i].x - r;
        y = map.goals[i].y - r;
        painter.drawEllipse(x, y, r, r);
    }

    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    r = map.start_pos.radius;
    x = map.start_pos.x - r;
    y = map.start_pos.y - r;
    painter.drawEllipse(x, y, r, r);
}
