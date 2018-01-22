//#include <QtOpenGL/QGLWidget>
#include <QtWidgets/QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonCharger, SIGNAL(clicked()), this, SLOT(onCharger()));
    connect(ui->buttonNoise, SIGNAL(clicked()), this, SLOT(onNoise()));

    //Placage de la fenêtre au centre
    QDesktopWidget bureau;
    QRect surface_bureau = bureau.screenGeometry();
    int x = surface_bureau.width()/2 - width()/2;
    int y = surface_bureau.height()/2 - height()/2;
    move(x,y);
}

void MainWindow::onNoise()
{
    noiseFct = true;

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
    ahf.normalize();
    ahf.saveImg("data/noise.ppm");

    ScalarField s1 = ahf.Slope();
    s1.saveImg("data/slope.ppm");

    ScalarField s2 = ahf.Drainage();
    s2.normalize();
    s2.saveImg("data/stream.ppm");

    Affiche();
}

void MainWindow::onCharger()
{
    noiseFct = false;

    QFileInfo file = QFileDialog::getOpenFileName(this, "Charger image");

    if(file.exists())
    {
        double x = 1000.0f;
        double y = 1000.0f;

        std::string filename_std = file.fileName().toStdString().c_str();
        noNoiseFilename = filename_std;
        filename_std = "data/" + filename_std;
        HeightField hf;
        hf.load(filename_std, Vector2(0,0), Vector2(x,y), 0, 100.0);

        ScalarField s1 = hf.Slope();
        s1.saveImg("data/slope.ppm");

        ScalarField s2 = hf.Drainage();
        s2.normalize();
        s2.saveImg("data/stream.ppm");

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

    str = QString::fromStdString("data/stream.ppm");
    image_affichee = QImage(str);
    image_affichee = image_affichee.scaled(ui->scrollAreaEau->width()-20, ui->scrollAreaEau->height()-20, Qt::KeepAspectRatio);
    px = QPixmap::fromImage(image_affichee);
    ui->labelEau->setPixmap(px);
}

MainWindow::~MainWindow()
{
    delete ui;
}
