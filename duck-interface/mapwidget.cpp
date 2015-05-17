#include "mapwidget.h"
#include "ui_mapwidget.h"

MapWidget::MapWidget(map_t *map, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);
    this->map = map;

//    this->setGeometry(0, 0, map->width, map->height);
    this->setMinimumWidth(map->width);
    this->setMinimumHeight(map->height);
}

MapWidget::~MapWidget()
{
    delete ui;
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    displayMap();
}

void MapWidget::displayMap()
{
    QPainter painter(this);

    //painter.drawLine(1,1,100,100);

    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::darkBlue, Qt::SolidPattern));

    int r, x, y;
    for (int i = 0; i < map->nb_blocks; i++) {
        r = map->blocks[i].radius;
        x = map->blocks[i].x - r;
        y = map->blocks[i].y - r;
        painter.drawEllipse(x, y, r*2, r*2);
    }

    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    for (int i = 0; i < map->nb_goals; i++) {
        r = map->goals[i].radius;
        x = map->goals[i].x - r;
        y = map->goals[i].y - r;
        painter.drawEllipse(x, y, r*2, r*2);
    }

    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    r = map->start_pos.radius;
    x = map->start_pos.x - r;
    y = map->start_pos.y - r;
    painter.drawEllipse(x, y, r*2, r*2);
}
