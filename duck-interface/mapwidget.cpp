#include "mapwidget.h"
#include "ui_mapwidget.h"

MapWidget::MapWidget(map_t *map, genotype_t *path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);
    this->map = map;
    this->path = path;

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
    if (path != NULL)
        displayPath();
}

void MapWidget::popUp()
{
    QDialog q;
    QVBoxLayout *l = new QVBoxLayout;

    l->addWidget(this);
    q.setLayout(l);
    q.adjustSize();

    q.exec();
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

void MapWidget::displayPath()
{
    QPainter painter(this);

    int i;
    map_object_t pos = map->start_pos;
    unsigned long reached_goals;

    QPainterPath q_path;
    q_path.moveTo(pos.x, pos.y);

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        evaluate_gene(path->genes[i], &pos, map, &reached_goals);
        q_path.lineTo(pos.x, pos.y);
    }

    painter.drawPath(q_path);
}
