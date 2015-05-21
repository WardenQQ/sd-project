#include "mapwidget.h"
#include "ui_mapwidget.h"

MapWidget::MapWidget(map_t &map, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);
    this->map = map;

    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));

    this->idx_in_gene = 0;
    this->idx_in_genotype = 0;
    pos = map.start_pos;

    this->has_path = false;

    this->setMinimumWidth(map.width);
    this->setMinimumHeight(map.height);
}

MapWidget::~MapWidget()
{
    delete ui;
}

void MapWidget::startPaintingPath(genotype_t &path, int refresh_interval)
{
    this->path = path;
    this->has_path = true;
    idx_in_gene = 0;
    idx_in_genotype = 0;
    pos = map.start_pos;
    reached_goals = 0;
    timer->start(refresh_interval);
}

void MapWidget::finishPaintingPath()
{
    timer->stop();
}

void MapWidget::animate()
{
    updatePosition();
    repaint();
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    displayMap(painter);
    if (has_path) {
        displayPath(painter);
        paintStep(painter);
    }

    painter.end();
}

void MapWidget::displayMap(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::darkBlue, Qt::SolidPattern));

    int r, x, y;
    for (int i = 0; i < map.nb_blocks; i++) {
        r = map.blocks[i].radius;
        x = map.blocks[i].x - r;
        y = map.blocks[i].y - r;
        painter.drawEllipse(x, y, r*2, r*2);
    }

    for (int i = 0; i < map.nb_goals; i++) {
        if ((reached_goals >> i) & 1) {
            painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        } else {
            painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
        }

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

void MapWidget::displayPath(QPainter &painter)
{
    int i, j;
    map_object_t pos = map.start_pos;
    map_object_t new_pos;
    unsigned long reached_goals = 0;
    unsigned long all_reached = pow(2, map.nb_goals) - 1;
    collision_info_t col;

    QPainterPath q_path;
    q_path.moveTo(pos.x, pos.y);
    painter.setBrush(QBrush());

    for (i = 0; i < GENOTYPE_SIZE && reached_goals != all_reached; i++) {
        col.block = 0;

        for (j = 0; j < path.genes[i].step  && !(col.block) && reached_goals != all_reached; j++) {
            new_pos = step_once(pos, path.genes[i].direction);
            col = look(&map, reached_goals, new_pos);

            if (!col.block) {
                pos = new_pos;
                reached_goals |= col.goal;
            }
        }

        q_path.lineTo(pos.x, pos.y);
    }

    painter.drawPath(q_path);
}

void MapWidget::paintStep(QPainter &painter)
{
    int r, x, y;
    painter.setBrush(QBrush(QColor(255, 175, 0), Qt::SolidPattern));
    r = pos.radius;
    x = pos.x - r;
    y = pos.y - r;
    painter.drawEllipse(x, y, r*2, r*2);
}

void MapWidget::updatePosition()
{
    if (idx_in_genotype < GENOTYPE_SIZE && reached_goals != pow(2, map.nb_goals) - 1) {
        if (idx_in_gene < path.genes[idx_in_genotype].step) {
            map_object_t new_pos = step_once(pos, path.genes[idx_in_genotype].direction);
            collision_info_t col = look(&map, reached_goals, pos);

            if (!col.block) {
                pos = new_pos;
                reached_goals |= col.goal;
            }

            idx_in_gene++;
        } else {
            idx_in_genotype++;
            idx_in_gene = 0;
        }
    } else {
        finishPaintingPath();
    }

}

void showPathDialog(map_t &map, genotype_t &path, QWidget *parent)
{
    MapWidget *m = new MapWidget(map, parent);
    QDialog *q = new QDialog();
    QVBoxLayout *l = new QVBoxLayout;

    l->addWidget(m);
    q->setLayout(l);
    q->adjustSize();

    m->startPaintingPath(path, 16);
    q->show();
}

void showMapDialog(map_t &map, QWidget *parent)
{
    MapWidget *m = new MapWidget(map, parent);
    QDialog *q = new QDialog();
    QVBoxLayout *l = new QVBoxLayout;

    l->addWidget(m);
    q->setLayout(l);
    q->adjustSize();

    q->show();
}
