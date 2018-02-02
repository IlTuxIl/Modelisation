#include "mainwindow.h"
#include <QFileDialog>
#include <Foret.h>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonCharger, SIGNAL(clicked()), this, SLOT(onCharger()));
    connect(ui->buttonNoise, SIGNAL(clicked()), this, SLOT(onNoise()));
}

void MainWindow::onNoise()
{
    std::vector<double> freq;
    std::vector<double> ampli;

    freq.push_back(5000.0);
    freq.push_back(2450.0);
    freq.push_back(1220.0);
    freq.push_back(550.0);

    ampli.push_back(300.0);
    ampli.push_back(140.0);
    ampli.push_back(65.0);
    ampli.push_back(30.0);

    double x = 10000.0f;
    double y = 10000.0f;

    AnalyticHeightField ahf(Vector2(0,0), Vector2(x,y), 100, 100, freq, ampli);
    ahf.normalize2();

    std::string filename_std("data/noise.ppm");
    ahf.saveImg(filename_std);
//
//    ScalarField s1 = ahf.Slope();
//    s1.saveImg("data/slope.ppm");
//
//    ScalarField s2 = ahf.Drainage();
//    s2.normalize();
//    s2.saveImg("data/drainage.ppm");

    Terrain t(ahf);
    Foret f = t.Vegetation(10.f);

    ScalarField drai = t.getDrainage().racineCarre();
    drai = drai.normalize();
    ScalarField slope = t.getSlope().normalize();
    ScalarField veget = f.toScalar().normalize();

    slope.saveImg("data/slope.ppm");
    drai.saveImg("data/drainage.ppm");
    veget.saveImg("data/veget.ppm");


    // TODO remplir image Foret -> s3.saveImg("../../data/veget.ppm");

    // TODO remplir image Route -> s4.saveImg("../../data/route.ppm");

    Affiche(filename_std);
}

void MainWindow::onCharger()
{
    QFileInfo file = QFileDialog::getOpenFileName(this, "Charger image");

    if(file.exists())
    {
        double x = 10000.0f;
        double y = 10000.0f;

        std::string filename_std = file.fileName().toStdString().c_str();
        filename_std = "data/" + filename_std;

        HeightField hf;
        hf.load(filename_std, Vector2(0,0), Vector2(x,y), 0, 700.f);

        Terrain t(hf);
        Foret f = t.Vegetation(10.f);

        ScalarField drai = t.getDrainage().racineCarre();
        drai = drai.normalize();
        ScalarField slope = t.getSlope().normalize();
        ScalarField veget = f.toScalar().normalize();

        slope.saveImg("data/slope.ppm");
        drai.saveImg("data/drainage.ppm");
        veget.saveImg("data/veget.ppm");

        // TODO remplir image Route -> s4.saveImg("../../data/route.ppm");

        Affiche(filename_std);
    }
}

void MainWindow::Affiche(std::string filename)
{
    QString str = QString::fromStdString(filename);
    QImage image_affichee = QImage(str);
    image_affichee = image_affichee.scaled(ui->scrollAreaHauteur->width()-20, ui->scrollAreaHauteur->height()-20, Qt::KeepAspectRatio);
    QPixmap px = QPixmap::fromImage(image_affichee);
    ui->labelHauteur->setPixmap(px);

    str = QString::fromStdString("data/slope.ppm");
    image_affichee = QImage(str);
    image_affichee = image_affichee.scaled(ui->scrollAreaPente->width()-20, ui->scrollAreaPente->height()-20, Qt::KeepAspectRatio);
    px = QPixmap::fromImage(image_affichee);
    ui->labelPente->setPixmap(px);

    str = QString::fromStdString("data/drainage.ppm");
    image_affichee = QImage(str);
    image_affichee = image_affichee.scaled(ui->scrollAreaEau->width()-20, ui->scrollAreaEau->height()-20, Qt::KeepAspectRatio);
    px = QPixmap::fromImage(image_affichee);
    ui->labelEau->setPixmap(px);

    str = QString::fromStdString("data/veget.ppm");
    image_affichee = QImage(str);
    image_affichee = image_affichee.scaled(ui->scrollAreaVegetation->width()-20, ui->scrollAreaVegetation->height()-20, Qt::KeepAspectRatio);
    px = QPixmap::fromImage(image_affichee);
    ui->labelVegetation->setPixmap(px);

    str = QString::fromStdString("data/route.ppm");
    image_affichee = QImage(str);
    image_affichee = image_affichee.scaled(ui->scrollAreaRoute->width()-20, ui->scrollAreaRoute->height()-20, Qt::KeepAspectRatio);
    px = QPixmap::fromImage(image_affichee);
    ui->labelRoute->setPixmap(px);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent (QCloseEvent * event)
{
    if(event != NULL) exit(0);
}
