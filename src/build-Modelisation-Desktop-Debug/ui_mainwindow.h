/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCharger;
    QAction *actionSauver;
    QAction *actionReset;
    QAction *actionNoise;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayouBouton;
    QPushButton *buttonCharger;
    QPushButton *buttonNoise;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_hauteur;
    QLabel *label_pente;
    QLabel *label_eau;
    QHBoxLayout *horizontalLayoutImage;
    QScrollArea *scrollAreaHauteur;
    QWidget *scrollAreaWidgetContentsHauteur;
    QLabel *labelHauteur;
    QScrollArea *scrollAreaPente;
    QWidget *scrollAreaWidgetContentsPente;
    QLabel *labelPente;
    QScrollArea *scrollAreaEau;
    QWidget *scrollAreaWidgetContentsEau;
    QLabel *labelEau;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_vegetation;
    QLabel *label_route;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayoutImage_2;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollAreaVegetation;
    QWidget *scrollAreaWidgetContentsVegetation;
    QLabel *labelVegetation;
    QScrollArea *scrollAreaRoute;
    QWidget *scrollAreaWidgetContentsRoute;
    QLabel *labelRoute;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionCharger = new QAction(MainWindow);
        actionCharger->setObjectName(QString::fromUtf8("actionCharger"));
        actionSauver = new QAction(MainWindow);
        actionSauver->setObjectName(QString::fromUtf8("actionSauver"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionNoise = new QAction(MainWindow);
        actionNoise->setObjectName(QString::fromUtf8("actionNoise"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 1921, 1081));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayouBouton = new QHBoxLayout();
        horizontalLayouBouton->setSpacing(6);
        horizontalLayouBouton->setObjectName(QString::fromUtf8("horizontalLayouBouton"));
        horizontalLayouBouton->setContentsMargins(30, 0, 10, -1);
        buttonCharger = new QPushButton(verticalLayoutWidget);
        buttonCharger->setObjectName(QString::fromUtf8("buttonCharger"));

        horizontalLayouBouton->addWidget(buttonCharger);

        buttonNoise = new QPushButton(verticalLayoutWidget);
        buttonNoise->setObjectName(QString::fromUtf8("buttonNoise"));

        horizontalLayouBouton->addWidget(buttonNoise);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayouBouton->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayouBouton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        label_hauteur = new QLabel(verticalLayoutWidget);
        label_hauteur->setObjectName(QString::fromUtf8("label_hauteur"));
        label_hauteur->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_hauteur);

        label_pente = new QLabel(verticalLayoutWidget);
        label_pente->setObjectName(QString::fromUtf8("label_pente"));
        label_pente->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_pente);

        label_eau = new QLabel(verticalLayoutWidget);
        label_eau->setObjectName(QString::fromUtf8("label_eau"));
        label_eau->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_eau);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayoutImage = new QHBoxLayout();
        horizontalLayoutImage->setSpacing(6);
        horizontalLayoutImage->setObjectName(QString::fromUtf8("horizontalLayoutImage"));
        horizontalLayoutImage->setContentsMargins(10, -1, 10, 0);
        scrollAreaHauteur = new QScrollArea(verticalLayoutWidget);
        scrollAreaHauteur->setObjectName(QString::fromUtf8("scrollAreaHauteur"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaHauteur->sizePolicy().hasHeightForWidth());
        scrollAreaHauteur->setSizePolicy(sizePolicy1);
        scrollAreaHauteur->setWidgetResizable(true);
        scrollAreaWidgetContentsHauteur = new QWidget();
        scrollAreaWidgetContentsHauteur->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsHauteur"));
        scrollAreaWidgetContentsHauteur->setGeometry(QRect(0, 0, 627, 489));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContentsHauteur->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContentsHauteur->setSizePolicy(sizePolicy1);
        labelHauteur = new QLabel(scrollAreaWidgetContentsHauteur);
        labelHauteur->setObjectName(QString::fromUtf8("labelHauteur"));
        labelHauteur->setGeometry(QRect(3, -4, 621, 471));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelHauteur->sizePolicy().hasHeightForWidth());
        labelHauteur->setSizePolicy(sizePolicy2);
        labelHauteur->setScaledContents(false);
        labelHauteur->setAlignment(Qt::AlignCenter);
        scrollAreaHauteur->setWidget(scrollAreaWidgetContentsHauteur);

        horizontalLayoutImage->addWidget(scrollAreaHauteur);

        scrollAreaPente = new QScrollArea(verticalLayoutWidget);
        scrollAreaPente->setObjectName(QString::fromUtf8("scrollAreaPente"));
        sizePolicy1.setHeightForWidth(scrollAreaPente->sizePolicy().hasHeightForWidth());
        scrollAreaPente->setSizePolicy(sizePolicy1);
        scrollAreaPente->setWidgetResizable(true);
        scrollAreaPente->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContentsPente = new QWidget();
        scrollAreaWidgetContentsPente->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsPente"));
        scrollAreaWidgetContentsPente->setGeometry(QRect(0, 0, 627, 489));
        labelPente = new QLabel(scrollAreaWidgetContentsPente);
        labelPente->setObjectName(QString::fromUtf8("labelPente"));
        labelPente->setGeometry(QRect(3, -4, 621, 471));
        labelPente->setAlignment(Qt::AlignCenter);
        scrollAreaPente->setWidget(scrollAreaWidgetContentsPente);

        horizontalLayoutImage->addWidget(scrollAreaPente);

        scrollAreaEau = new QScrollArea(verticalLayoutWidget);
        scrollAreaEau->setObjectName(QString::fromUtf8("scrollAreaEau"));
        sizePolicy1.setHeightForWidth(scrollAreaEau->sizePolicy().hasHeightForWidth());
        scrollAreaEau->setSizePolicy(sizePolicy1);
        scrollAreaEau->setWidgetResizable(true);
        scrollAreaWidgetContentsEau = new QWidget();
        scrollAreaWidgetContentsEau->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsEau"));
        scrollAreaWidgetContentsEau->setGeometry(QRect(0, 0, 627, 489));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContentsEau->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContentsEau->setSizePolicy(sizePolicy1);
        labelEau = new QLabel(scrollAreaWidgetContentsEau);
        labelEau->setObjectName(QString::fromUtf8("labelEau"));
        labelEau->setGeometry(QRect(3, -4, 621, 471));
        labelEau->setAlignment(Qt::AlignCenter);
        scrollAreaEau->setWidget(scrollAreaWidgetContentsEau);

        horizontalLayoutImage->addWidget(scrollAreaEau);


        verticalLayout->addLayout(horizontalLayoutImage);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer_5 = new QSpacerItem(310, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        label_vegetation = new QLabel(verticalLayoutWidget);
        label_vegetation->setObjectName(QString::fromUtf8("label_vegetation"));
        label_vegetation->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_vegetation);

        label_route = new QLabel(verticalLayoutWidget);
        label_route->setObjectName(QString::fromUtf8("label_route"));
        label_route->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_route);

        horizontalSpacer_4 = new QSpacerItem(310, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayoutImage_2 = new QHBoxLayout();
        horizontalLayoutImage_2->setSpacing(6);
        horizontalLayoutImage_2->setObjectName(QString::fromUtf8("horizontalLayoutImage_2"));
        horizontalLayoutImage_2->setContentsMargins(10, 0, 10, 0);
        horizontalSpacer_2 = new QSpacerItem(310, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayoutImage_2->addItem(horizontalSpacer_2);

        scrollAreaVegetation = new QScrollArea(verticalLayoutWidget);
        scrollAreaVegetation->setObjectName(QString::fromUtf8("scrollAreaVegetation"));
        sizePolicy1.setHeightForWidth(scrollAreaVegetation->sizePolicy().hasHeightForWidth());
        scrollAreaVegetation->setSizePolicy(sizePolicy1);
        scrollAreaVegetation->setWidgetResizable(true);
        scrollAreaWidgetContentsVegetation = new QWidget();
        scrollAreaWidgetContentsVegetation->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsVegetation"));
        scrollAreaWidgetContentsVegetation->setGeometry(QRect(0, 0, 629, 488));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContentsVegetation->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContentsVegetation->setSizePolicy(sizePolicy1);
        labelVegetation = new QLabel(scrollAreaWidgetContentsVegetation);
        labelVegetation->setObjectName(QString::fromUtf8("labelVegetation"));
        labelVegetation->setGeometry(QRect(3, 6, 621, 461));
        sizePolicy2.setHeightForWidth(labelVegetation->sizePolicy().hasHeightForWidth());
        labelVegetation->setSizePolicy(sizePolicy2);
        labelVegetation->setScaledContents(false);
        labelVegetation->setAlignment(Qt::AlignCenter);
        scrollAreaVegetation->setWidget(scrollAreaWidgetContentsVegetation);

        horizontalLayoutImage_2->addWidget(scrollAreaVegetation);

        scrollAreaRoute = new QScrollArea(verticalLayoutWidget);
        scrollAreaRoute->setObjectName(QString::fromUtf8("scrollAreaRoute"));
        sizePolicy1.setHeightForWidth(scrollAreaRoute->sizePolicy().hasHeightForWidth());
        scrollAreaRoute->setSizePolicy(sizePolicy1);
        scrollAreaRoute->setWidgetResizable(true);
        scrollAreaWidgetContentsRoute = new QWidget();
        scrollAreaWidgetContentsRoute->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsRoute"));
        scrollAreaWidgetContentsRoute->setGeometry(QRect(0, 0, 628, 488));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContentsRoute->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContentsRoute->setSizePolicy(sizePolicy1);
        labelRoute = new QLabel(scrollAreaWidgetContentsRoute);
        labelRoute->setObjectName(QString::fromUtf8("labelRoute"));
        labelRoute->setGeometry(QRect(3, 6, 621, 461));
        sizePolicy2.setHeightForWidth(labelRoute->sizePolicy().hasHeightForWidth());
        labelRoute->setSizePolicy(sizePolicy2);
        labelRoute->setScaledContents(false);
        labelRoute->setAlignment(Qt::AlignCenter);
        scrollAreaRoute->setWidget(scrollAreaWidgetContentsRoute);

        horizontalLayoutImage_2->addWidget(scrollAreaRoute);

        horizontalSpacer_3 = new QSpacerItem(310, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayoutImage_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayoutImage_2);

        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(4, 1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCharger->setText(QApplication::translate("MainWindow", "Charger", 0, QApplication::UnicodeUTF8));
        actionSauver->setText(QApplication::translate("MainWindow", "Sauver", 0, QApplication::UnicodeUTF8));
        actionReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        actionNoise->setText(QApplication::translate("MainWindow", "Noise", 0, QApplication::UnicodeUTF8));
        buttonCharger->setText(QApplication::translate("MainWindow", "Charger", 0, QApplication::UnicodeUTF8));
        buttonNoise->setText(QApplication::translate("MainWindow", "Noise", 0, QApplication::UnicodeUTF8));
        label_hauteur->setText(QApplication::translate("MainWindow", "Hauteur", 0, QApplication::UnicodeUTF8));
        label_pente->setText(QApplication::translate("MainWindow", "Pente", 0, QApplication::UnicodeUTF8));
        label_eau->setText(QApplication::translate("MainWindow", "Drainage", 0, QApplication::UnicodeUTF8));
        labelHauteur->setText(QString());
        labelPente->setText(QString());
        labelEau->setText(QString());
        label_vegetation->setText(QApplication::translate("MainWindow", "Vegetation", 0, QApplication::UnicodeUTF8));
        label_route->setText(QApplication::translate("MainWindow", "Route", 0, QApplication::UnicodeUTF8));
        labelVegetation->setText(QString());
        labelRoute->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
