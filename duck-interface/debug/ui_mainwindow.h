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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpinBox *sb_width;
    QLabel *label_12;
    QSpinBox *sb_stepMax;
    QSpinBox *sb_height;
    QSpinBox *sb_stepMin;
    QLabel *label_3;
    QLabel *label_4;
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
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_10;
    QSpinBox *spinBox_11;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QWidget *tab1;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QWidget *tab2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(442, 551);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        sb_width = new QSpinBox(groupBox);
        sb_width->setObjectName(QStringLiteral("sb_width"));
        sb_width->setMinimum(50);
        sb_width->setMaximum(1000);
        sb_width->setSingleStep(10);

        gridLayout_2->addWidget(sb_width, 0, 5, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        sb_stepMax = new QSpinBox(groupBox);
        sb_stepMax->setObjectName(QStringLiteral("sb_stepMax"));
        sb_stepMax->setMinimum(2);
        sb_stepMax->setMaximum(50);

        gridLayout_2->addWidget(sb_stepMax, 1, 5, 1, 1);

        sb_height = new QSpinBox(groupBox);
        sb_height->setObjectName(QStringLiteral("sb_height"));
        sb_height->setMinimum(50);
        sb_height->setMaximum(800);
        sb_height->setSingleStep(10);

        gridLayout_2->addWidget(sb_height, 0, 1, 1, 1);

        sb_stepMin = new QSpinBox(groupBox);
        sb_stepMin->setObjectName(QStringLiteral("sb_stepMin"));
        sb_stepMin->setMinimum(1);
        sb_stepMin->setMaximum(20);

        gridLayout_2->addWidget(sb_stepMin, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 4, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 1, 4, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
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
        sb_radius_max->setMaximum(50);

        gridLayout_3->addWidget(sb_radius_max, 0, 4, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 0, 3, 1, 1);

        sb_blocks = new QSpinBox(groupBox_2);
        sb_blocks->setObjectName(QStringLiteral("sb_blocks"));
        sb_blocks->setMaximum(20);

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
        sb_radius_min->setMaximum(50);

        gridLayout_3->addWidget(sb_radius_min, 0, 1, 1, 1);

        sb_goals = new QSpinBox(groupBox_2);
        sb_goals->setObjectName(QStringLiteral("sb_goals"));
        sb_goals->setMinimum(1);
        sb_goals->setMaximum(20);

        gridLayout_3->addWidget(sb_goals, 1, 4, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox_3 = new QGroupBox(tab);
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

        spinBox_11 = new QSpinBox(groupBox_3);
        spinBox_11->setObjectName(QStringLiteral("spinBox_11"));
        spinBox_11->setMinimum(1);
        spinBox_11->setMaximum(100);
        spinBox_11->setValue(50);

        gridLayout_4->addWidget(spinBox_11, 1, 1, 1, 1);

        spinBox_8 = new QSpinBox(groupBox_3);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setMinimum(0);
        spinBox_8->setMaximum(100);

        gridLayout_4->addWidget(spinBox_8, 2, 1, 1, 1);

        spinBox_7 = new QSpinBox(groupBox_3);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setMinimum(1);
        spinBox_7->setMaximum(100);
        spinBox_7->setValue(3);

        gridLayout_4->addWidget(spinBox_7, 0, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        lineEdit = new QLineEdit(tab1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 60, 146, 31));
        label = new QLabel(tab1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 81, 21));
        lineEdit_2 = new QLineEdit(tab1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 130, 146, 31));
        label_2 = new QLabel(tab1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 81, 21));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tabWidget->addTab(tab2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 442, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "I Wanna be a duck...", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Dimensions de la carte", 0));
        sb_width->setSuffix(QApplication::translate("MainWindow", "px", 0));
        label_12->setText(QApplication::translate("MainWindow", "Taille de pas max", 0));
        sb_height->setSuffix(QApplication::translate("MainWindow", "px", 0));
        label_3->setText(QApplication::translate("MainWindow", "Largeur", 0));
        label_4->setText(QApplication::translate("MainWindow", "Hauteur", 0));
        label_11->setText(QApplication::translate("MainWindow", "Taille de pas min", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Obstacles et objectifs", 0));
        label_5->setText(QApplication::translate("MainWindow", "Nombre d'obstacles", 0));
        label_7->setText(QApplication::translate("MainWindow", "Taille d'objet max", 0));
        label_6->setText(QApplication::translate("MainWindow", "Nombre d'objectifs", 0));
        label_8->setText(QApplication::translate("MainWindow", "Taille d'objet min", 0));
        pushButton->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer une carte al\303\251atoire", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Param\303\250tre de l'algorithme g\303\251netique", 0));
        label_9->setText(QApplication::translate("MainWindow", "Probabilit\303\251 de mutation", 0));
        label_13->setText(QApplication::translate("MainWindow", "Fr\303\251quence de migration", 0));
        label_10->setText(QApplication::translate("MainWindow", "Nombre d'enfants par g\303\251n\303\251ration", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Cr\303\251er un nouveau cluster", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Cr\303\251er un cluster", 0));
        label->setText(QApplication::translate("MainWindow", "Hostname : ", 0));
        label_2->setText(QApplication::translate("MainWindow", "Version : ", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "Rejoindre un cluster", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "Voir les r\303\251sultats", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
