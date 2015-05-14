#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(0, 0, LENGTH, HEIGHT);

    random_map(&(this->map), 9, 9);

    srand(time(NULL));

    best = genetic_algorithm(1000, 50, &map, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    this->displayMap();
    this->displayPath();
}

void MainWindow::displayMap()
{
    QPainter painter(this);

    //painter.drawLine(1,1,100,100);

    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::darkBlue, Qt::SolidPattern));

    int r, x, y;
    for (int i = 0; i < map.nb_blocks; i++) {
        r = map.blocks[i].radius;
        x = map.blocks[i].x - r;
        y = map.blocks[i].y - r;
        painter.drawEllipse(x, y, r*2, r*2);
    }

    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    for (int i = 0; i < map.nb_goals; i++) {
        r = map.goals[i].radius;
        x = map.goals[i].x - r;
        y = map.goals[i].y - r;
        painter.drawEllipse(x, y, r*2, r*2);
    }

    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    r = map.start_pos.radius;
    x = map.start_pos.x - r;
    y = map.start_pos.y - r;
    painter.drawEllipse(x, y, r*2, r*2);
}


void MainWindow::displayPath()
{
    QPainter painter(this);

    int i;
    map_object_t pos = map.start_pos;
    unsigned long reached_goals;

    QPainterPath path;
    path.moveTo(pos.x, pos.y);

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        evaluate_gene(best.genes[i], &pos, &map, &reached_goals);
        path.lineTo(pos.x, pos.y);
    }

    painter.drawPath(path);
}
