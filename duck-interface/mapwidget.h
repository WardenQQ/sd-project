#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "../map.h"

#include <QtGui>
#include <QWidget>

namespace Ui {
class MapWidget;
}

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(map_t *map, QWidget *parent = 0);
    ~MapWidget();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MapWidget *ui;
    map_t *map;
    void displayMap();
};

#endif // MAPWIDGET_H
