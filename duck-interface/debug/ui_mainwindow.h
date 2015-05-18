/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpinBox *sb_width;
    QSpinBox *sb_stepMax;
    QSpinBox *sb_height;
    QSpinBox *sb_stepMin;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_12;
    QLabel *label_11;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QSpinBox *sb_radius_max;
    QLabel *label_7;
    QSpinBox *sb_blocks;
    QLabel *label_6;
    QLabel *label_8;
    QSpinBox *sb_radius_min;
    QSpinBox *sb_goals;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_generate_map;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_10;
    QSpinBox *sb_children;
    QSpinBox *sb_migration;
    QSpinBox *sb_mutation;
    QFrame *line;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_17;
    QComboBox *cb_ip;
    QLabel *label_15;
    QSpinBox *sb_vers;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_init_cluster;
    QWidget *page_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *txt_contact_ip;
    QLabel *label_14;
    QSpinBox *sb_contact_id;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_18;
    QComboBox *cb_ip_2;
    QLabel *label_19;
    QSpinBox *sb_vers_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_join_cluster;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_20;
    QLineEdit *txt_res_ip;
    QLabel *label_21;
    QSpinBox *sb_res_id;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_refresh;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_display_path;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(576, 750);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        toolBox = new QToolBox(tab);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 536, 565));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        sb_width = new QSpinBox(groupBox);
        sb_width->setObjectName(QStringLiteral("sb_width"));
        sb_width->setMinimum(100);
        sb_width->setMaximum(1000);
        sb_width->setSingleStep(10);
        sb_width->setValue(800);

        gridLayout_2->addWidget(sb_width, 0, 6, 1, 1);

        sb_stepMax = new QSpinBox(groupBox);
        sb_stepMax->setObjectName(QStringLiteral("sb_stepMax"));
        sb_stepMax->setMinimum(1);
        sb_stepMax->setMaximum(100);
        sb_stepMax->setValue(10);

        gridLayout_2->addWidget(sb_stepMax, 1, 6, 1, 1);

        sb_height = new QSpinBox(groupBox);
        sb_height->setObjectName(QStringLiteral("sb_height"));
        sb_height->setMinimum(100);
        sb_height->setMaximum(800);
        sb_height->setSingleStep(10);
        sb_height->setValue(600);

        gridLayout_2->addWidget(sb_height, 0, 2, 1, 1);

        sb_stepMin = new QSpinBox(groupBox);
        sb_stepMin->setObjectName(QStringLiteral("sb_stepMin"));
        sb_stepMin->setMinimum(1);
        sb_stepMin->setMaximum(100);

        gridLayout_2->addWidget(sb_stepMin, 1, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 5, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 1, 5, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        sb_radius_max = new QSpinBox(groupBox_2);
        sb_radius_max->setObjectName(QStringLiteral("sb_radius_max"));
        sb_radius_max->setMinimum(10);
        sb_radius_max->setMaximum(100);

        gridLayout_3->addWidget(sb_radius_max, 0, 4, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 0, 3, 1, 1);

        sb_blocks = new QSpinBox(groupBox_2);
        sb_blocks->setObjectName(QStringLiteral("sb_blocks"));
        sb_blocks->setMaximum(32);

        gridLayout_3->addWidget(sb_blocks, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        sb_radius_min = new QSpinBox(groupBox_2);
        sb_radius_min->setObjectName(QStringLiteral("sb_radius_min"));
        sb_radius_min->setMinimum(10);
        sb_radius_min->setMaximum(100);

        gridLayout_3->addWidget(sb_radius_min, 0, 1, 1, 1);

        sb_goals = new QSpinBox(groupBox_2);
        sb_goals->setObjectName(QStringLiteral("sb_goals"));
        sb_goals->setMinimum(1);
        sb_goals->setMaximum(32);

        gridLayout_3->addWidget(sb_goals, 1, 4, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_generate_map = new QPushButton(page);
        btn_generate_map->setObjectName(QStringLiteral("btn_generate_map"));

        horizontalLayout->addWidget(btn_generate_map);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        line_4 = new QFrame(page);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_4->addWidget(label_13, 2, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        sb_children = new QSpinBox(groupBox_3);
        sb_children->setObjectName(QStringLiteral("sb_children"));
        sb_children->setMinimum(1);
        sb_children->setMaximum(100);
        sb_children->setValue(50);

        gridLayout_4->addWidget(sb_children, 1, 1, 1, 1);

        sb_migration = new QSpinBox(groupBox_3);
        sb_migration->setObjectName(QStringLiteral("sb_migration"));
        sb_migration->setMinimum(1);
        sb_migration->setMaximum(100);
        sb_migration->setValue(1);

        gridLayout_4->addWidget(sb_migration, 2, 1, 1, 1);

        sb_mutation = new QSpinBox(groupBox_3);
        sb_mutation->setObjectName(QStringLiteral("sb_mutation"));
        sb_mutation->setMinimum(1);
        sb_mutation->setMaximum(100);
        sb_mutation->setValue(3);

        gridLayout_4->addWidget(sb_mutation, 0, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);

        line = new QFrame(page);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        groupBox_6 = new QGroupBox(page);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_4->addWidget(label_17);

        cb_ip = new QComboBox(groupBox_6);
        cb_ip->setObjectName(QStringLiteral("cb_ip"));
        cb_ip->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(cb_ip);

        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_4->addWidget(label_15);

        sb_vers = new QSpinBox(groupBox_6);
        sb_vers->setObjectName(QStringLiteral("sb_vers"));

        horizontalLayout_4->addWidget(sb_vers);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btn_init_cluster = new QPushButton(groupBox_6);
        btn_init_cluster->setObjectName(QStringLiteral("btn_init_cluster"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        btn_init_cluster->setFont(font);

        horizontalLayout_4->addWidget(btn_init_cluster);


        verticalLayout_3->addWidget(groupBox_6);

        toolBox->addItem(page, QString::fromUtf8("Cr\303\251er un cluster"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 536, 565));
        verticalLayout = new QVBoxLayout(page_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_5 = new QGroupBox(page_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_5->addWidget(label_16);

        txt_contact_ip = new QLineEdit(groupBox_5);
        txt_contact_ip->setObjectName(QStringLiteral("txt_contact_ip"));
        txt_contact_ip->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(txt_contact_ip);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_5->addWidget(label_14);

        sb_contact_id = new QSpinBox(groupBox_5);
        sb_contact_id->setObjectName(QStringLiteral("sb_contact_id"));

        horizontalLayout_5->addWidget(sb_contact_id);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(groupBox_5);

        groupBox_7 = new QGroupBox(page_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_7);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_3->addWidget(label_18);

        cb_ip_2 = new QComboBox(groupBox_7);
        cb_ip_2->setObjectName(QStringLiteral("cb_ip_2"));
        cb_ip_2->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(cb_ip_2);

        label_19 = new QLabel(groupBox_7);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_3->addWidget(label_19);

        sb_vers_2 = new QSpinBox(groupBox_7);
        sb_vers_2->setObjectName(QStringLiteral("sb_vers_2"));

        horizontalLayout_3->addWidget(sb_vers_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        btn_join_cluster = new QPushButton(groupBox_7);
        btn_join_cluster->setObjectName(QStringLiteral("btn_join_cluster"));
        btn_join_cluster->setFont(font);

        horizontalLayout_3->addWidget(btn_join_cluster);


        verticalLayout->addWidget(groupBox_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        toolBox->addItem(page_2, QStringLiteral("Rejoindre un cluster"));
        groupBox_5->raise();
        groupBox_7->raise();

        verticalLayout_2->addWidget(toolBox);

        tabWidget->addTab(tab, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        verticalLayout_5 = new QVBoxLayout(tab2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_8 = new QGroupBox(tab2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_8);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_20 = new QLabel(groupBox_8);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_6->addWidget(label_20);

        txt_res_ip = new QLineEdit(groupBox_8);
        txt_res_ip->setObjectName(QStringLiteral("txt_res_ip"));
        txt_res_ip->setMinimumSize(QSize(150, 0));

        horizontalLayout_6->addWidget(txt_res_ip);

        label_21 = new QLabel(groupBox_8);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_6->addWidget(label_21);

        sb_res_id = new QSpinBox(groupBox_8);
        sb_res_id->setObjectName(QStringLiteral("sb_res_id"));

        horizontalLayout_6->addWidget(sb_res_id);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        btn_refresh = new QPushButton(groupBox_8);
        btn_refresh->setObjectName(QStringLiteral("btn_refresh"));

        horizontalLayout_6->addWidget(btn_refresh);


        verticalLayout_5->addWidget(groupBox_8);

        listWidget = new QListWidget(tab2);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_5->addWidget(listWidget);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        btn_display_path = new QPushButton(tab2);
        btn_display_path->setObjectName(QStringLiteral("btn_display_path"));

        horizontalLayout_7->addWidget(btn_display_path);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 275, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        tabWidget->addTab(tab2, QString());

        verticalLayout_4->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 576, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "I Wanna be a duck...", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Dimensions de la carte", 0));
        sb_width->setSuffix(QApplication::translate("MainWindow", "px", 0));
        sb_height->setSuffix(QApplication::translate("MainWindow", "px", 0));
        label_3->setText(QApplication::translate("MainWindow", "Largeur", 0));
        label_4->setText(QApplication::translate("MainWindow", "Hauteur", 0));
        label_12->setText(QApplication::translate("MainWindow", "Taille de pas max", 0));
        label_11->setText(QApplication::translate("MainWindow", "Taille de pas min", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Obstacles et objectifs", 0));
        label_5->setText(QApplication::translate("MainWindow", "Nombre d'obstacles", 0));
        label_7->setText(QApplication::translate("MainWindow", "Taille d'objet max", 0));
        label_6->setText(QApplication::translate("MainWindow", "Nombre d'objectifs", 0));
        label_8->setText(QApplication::translate("MainWindow", "Taille d'objet min", 0));
        btn_generate_map->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer une carte al\303\251atoire", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Algorithme g\303\251netique", 0));
        label_9->setText(QApplication::translate("MainWindow", "Probabilit\303\251 de mutation", 0));
        label_13->setText(QApplication::translate("MainWindow", "Fr\303\251quence de migration", 0));
        label_10->setText(QApplication::translate("MainWindow", "Nombre d'enfants par g\303\251n\303\251ration", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Nouveau n\305\223ud", 0));
        label_17->setText(QApplication::translate("MainWindow", "Adresse IP", 0));
        label_15->setText(QApplication::translate("MainWindow", "Identifiant", 0));
        btn_init_cluster->setText(QApplication::translate("MainWindow", "Lancer !", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Cr\303\251er un cluster", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "N\305\223ud \303\240 contacter", 0));
        label_16->setText(QApplication::translate("MainWindow", "Adresse IP", 0));
        txt_contact_ip->setInputMask(QApplication::translate("MainWindow", "000.000.000.000;_", 0));
        txt_contact_ip->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        label_14->setText(QApplication::translate("MainWindow", "Identifiant", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Nouveau n\305\223ud", 0));
        label_18->setText(QApplication::translate("MainWindow", "Adresse IP", 0));
        label_19->setText(QApplication::translate("MainWindow", "Identifiant", 0));
        btn_join_cluster->setText(QApplication::translate("MainWindow", "Lancer !", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Rejoindre un cluster", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Param\303\250tres", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "N\305\223ud \303\240 contacter", 0));
        label_20->setText(QApplication::translate("MainWindow", "Adresse IP", 0));
        txt_res_ip->setInputMask(QApplication::translate("MainWindow", "000.000.000.000;_", 0));
        txt_res_ip->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        label_21->setText(QApplication::translate("MainWindow", "Identifiant", 0));
        btn_refresh->setText(QApplication::translate("MainWindow", "Actualiser", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Veuillez actualiser pour voir les r\303\251sultats", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        btn_display_path->setText(QApplication::translate("MainWindow", "Afficher le chemin", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "Voir les r\303\251sultats", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
