#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapwidget.h"

#include <QDialog>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_pushButton_clicked()
{
    random_map(&map, ui->sb_width->value(), ui->sb_height->value(), ui->sb_blocks->value(), ui->sb_goals->value(), ui->sb_stepMin->value(), ui->sb_stepMax->value(), ui->sb_radius_min->value(), ui->sb_radius_max->value(), ui->sb_mutation->value(), ui->sb_children->value(), ui->sb_migration->value());

    QDialog q;
    QVBoxLayout *l = new QVBoxLayout;
    MapWidget *m = new MapWidget(&map, this);

    l->addWidget(m);
    q.setLayout(l);
    q.adjustSize();

    q.exec();
}
