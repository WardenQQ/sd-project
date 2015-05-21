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

void MapWidget::displayPath(QPainter &painter)
{
    int i;
    map_object_t pos = map.start_pos;
    unsigned long reached_goals;

    QPainterPath q_path;
    q_path.moveTo(pos.x, pos.y);
    painter.setBrush(QBrush());

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        evaluate_gene(path.genes[i], &pos, &map, &reached_goals);
        q_path.lineTo(pos.x, pos.y);
    }

    painter.drawPath(q_path);
}

void MapWidget::paintStep(QPainter &painter)
{
    int r, x, y;
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    r = pos.radius;
    x = pos.x - r;
    y = pos.y - r;
    painter.drawEllipse(x, y, r*2, r*2);
}

void MapWidget::updatePosition()
{
    if (idx_in_gene < path.genes[idx_in_genotype].step) {
        idx_in_gene++;
    } else {
        if (idx_in_genotype < GENOTYPE_SIZE) {
            idx_in_genotype++;
            idx_in_gene = 0;
        } else {
            finishPaintingPath();
        }
    }


    map_object_t new_pos = compute_position(pos, path.genes[idx_in_genotype].direction);

    if (!in_boundary(&map, new_pos)) {
        return;
    }
    for (int j = 0; j < map.nb_blocks; j++) {
        if (collides_with(new_pos, map.blocks[j])) {
            return;
        }
    }
    pos = new_pos;
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
