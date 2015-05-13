#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include "../map.h"
#include "../genotype.h"
#include "../population.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);


private:
    Ui::MainWindow *ui;
    map_t map;
    genotype_t best;
    void displayMap();
    void displayPath();
};

#endif // MAINWINDOW_H