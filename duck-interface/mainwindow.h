#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <string.h>
#include <QListWidgetItem>
#include "mapwidget.h"
#include "../map.h"
#include "../genotype.h"
#include "../population.h"
#include "../server.h"
#include "../client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btn_generate_map_clicked();

    void on_btn_init_cluster_clicked();

    void on_btn_join_cluster_clicked();

    void on_btn_refresh_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    map_t map;
    genotype_t bests[SERVER_LIST_MAX];
    void displayMap();
    void setIP();
    void setGAParameters();
    void setMapParameters();
};

#endif // MAINWINDOW_H
