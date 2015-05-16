#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    random_map(&(w.map), 9, 9);
    srand(time(NULL));
//    thread t1(genetic_algorithm, 1000, 50, &map, &best, 0);
//    t1.join;

    w.show();

    return a.exec();
}
