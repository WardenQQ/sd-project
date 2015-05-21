#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "../map.h"

#include <QtGui>
#include <QDialog>
#include <QWidget>

namespace Ui {
class MapWidget;
}

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(map_t &map, QWidget *parent = 0);
    ~MapWidget();
    void startPaintingPath(genotype_t &path, int refresh_interval);
    void finishPaintingPath();

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MapWidget *ui;
    QTimer *timer;

    map_t map;
    genotype_t path;
    int idx_in_genotype;
    int idx_in_gene;
    map_object_t pos;
    unsigned long reached_goals;

    bool has_path;

    void displayMap(QPainter &painter);
    void displayPath(QPainter &painter);
    void paintStep(QPainter &painter);
    void updatePosition();
};

void showMapDialog(map_t &map, QWidget *parent = 0);

void showPathDialog(map_t &map, genotype_t &path, QWidget *parent = 0);

#endif // MAPWIDGET_H
