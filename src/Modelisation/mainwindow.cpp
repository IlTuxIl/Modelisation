#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonCharger, SIGNAL(clicked()), this, SLOT(onCharger()));
    connect(ui->buttonReset, SIGNAL(clicked()), this, SLOT(onReset()));

    connect(ui->buttonNoise, SIGNAL(clicked()), this, SLOT(onNoise()));

    results = new Results();
}

void MainWindow::Affiche()
{
    Image image = *results->img_hauteur;
    QImage image_affichee = QImage((uchar*)image.getValues(), image.getWidth(), image.getHeight(), QImage::Format_RGB32);
    QPixmap px = QPixmap::fromImage(image_affichee);
    ui->labelHauteur->setPixmap(px);

    /*image = *results->img_pente;
    image_affichee = QImage((uchar*)image.getValues(), image.getWidth(), image.getHeight(), QImage::Format_RGB32);
    px = QPixmap::fromImage(image_affichee);
    ui->labelPente->setPixmap(px);

    image = *results->img_eau;
    image_affichee = QImage((uchar*)image.getValues(), image.getWidth(), image.getHeight(), QImage::Format_RGB32);
    px = QPixmap::fromImage(image_affichee);
    ui->labelEau->setPixmap(px);*/
}

void MainWindow::onCharger()
{
    QFileInfo file = QFileDialog::getOpenFileName(this, "Charger image");

    if(file.exists())
    {
        results->SetImage(file.absoluteFilePath().toStdString().c_str());
        Affiche();
    }
}

void MainWindow::onReset()
{
    *results->img_hauteur = Image();
    *results->img_pente = Image();
    *results->img_eau = Image();

    Affiche();
}

MainWindow::~MainWindow()
{
    delete ui;
}
