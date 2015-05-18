#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QVBoxLayout>
#include <unistd.h>
#include <QHostAddress>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setIP();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayMap()
{
    QPainter painter(this);

    //painter.drawLine(1,1,100,100);

    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
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


void MainWindow::displayPath()
{
    QPainter painter(this);

    int i;
    map_object_t pos = map.start_pos;
    unsigned long reached_goals;

    QPainterPath path;
    path.moveTo(pos.x, pos.y);

    for (i = 0; i < GENOTYPE_SIZE; i++) {
        evaluate_gene(best.genes[i], &pos, &map, &reached_goals);
        path.lineTo(pos.x, pos.y);
    }

    painter.drawPath(path);
}

void MainWindow::setGAParameters()
{
    map.mutation_prob = ui->sb_mutation->value();
    map.nb_children = ui->sb_children->value();
    map.migration_freq = ui->sb_migration->value();
}

void MainWindow::on_btn_generate_map_clicked()
{
    map.width = ui->sb_width->value();
    map.height = ui->sb_height->value();
    map.nb_blocks = ui->sb_blocks->value();
    map.nb_goals = ui->sb_goals->value();
    map.min_step = ui->sb_stepMin->value();
    map.max_step = ui->sb_stepMax->value();
    map.min_radius = ui->sb_radius_min->value();
    map.max_radius = ui->sb_radius_max->value();
    random_map(&map);

    QDialog q;
    QVBoxLayout *l = new QVBoxLayout;
    MapWidget *m = new MapWidget(&map, this);

    l->addWidget(m);
    q.setLayout(l);
    q.adjustSize();

    q.exec();
}

void MainWindow::on_btn_init_cluster_clicked()
{
    setGAParameters();

    if (fork() == 0) {
        server(ui->sb_vers->value());
    } else {
        if (fork() == 0) {
            server_address_t self;
            self.id = ui->sb_vers->value();
            strncpy(self.hostname, ui->cb_ip->currentText().toLocal8Bit().data(), 64);

            client_init(self, map);
            exit(0);
        }
    }
}

void MainWindow::on_btn_join_cluster_clicked()
{
    setGAParameters();

    if (fork() == 0) {
       server(ui->sb_vers_2->value());
    } else {
        if (fork() == 0) {
            server_address_t self, contact;
            self.id = ui->sb_vers_2->value();
            strncpy(self.hostname, ui->cb_ip_2->currentText().toLocal8Bit().data(), 64);
    
            QString qs = ui->txt_contact_ip->text().remove(QRegExp("_"));
            strncpy(contact.hostname, qs.toLocal8Bit().data(), 64);
            contact.id = ui->sb_contact_id->value();
            client_join(self, contact);
            exit(0);
        }
    }
}

void MainWindow::setIP()
{
    foreach ( const QHostAddress &addr, QNetworkInterface::allAddresses() )
        if ( addr.protocol() == QAbstractSocket::IPv4Protocol && addr != QHostAddress(QHostAddress::LocalHost) ) {
            ui->cb_ip->addItem(addr.toString());
            ui->cb_ip_2->addItem(addr.toString());
            ui->txt_contact_ip->setText(addr.toString());
            ui->txt_res_ip->setText(addr.toString());
        }
}

void MainWindow::on_btn_refresh_clicked()
{
    int ret = 0;
    server_list_t list;
    server_address_t contact;
    contact.id = ui->sb_res_id->value();
    strncpy(contact.hostname, ui->txt_res_ip->text().remove(QRegExp("_")).toLocal8Bit().data(), 64);

    callrpc(contact.hostname, PROGNUM, contact.id, PROC_GIVE_SERVER_LIST,
            (xdrproc_t)xdr_void, (char *)&ret, (xdrproc_t)xdr_server_list_t, (char *)&list);

    ui->listWidget->clear();
    for(int i = 0; i < list.size; i++) {
        QString text = QString(list.addr[i].hostname).append(" \t%0").arg(list.addr[i].id).append(" ");
        ui->listWidget->addItem(text);
    }
    QString text = QString("127.0.0.1").append(" \t%0").arg(contact.id).append(" ");
    ui->listWidget->addItem(text);
}
