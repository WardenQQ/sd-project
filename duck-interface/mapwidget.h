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
    explicit MapWidget(map_t *map, genotype_t *path = NULL, QWidget *parent = 0);
    ~MapWidget();
    void popUp();
    static void popUpMap(map_t *map);
    static void popUpPath(map_t *map, genotype_t g);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MapWidget *ui;
    map_t *map;
    genotype_t *path;
    void displayMap();
    void displayPath();
};

#endif // MAPWIDGET_H
