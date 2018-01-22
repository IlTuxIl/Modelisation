#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL/QGLWidget>
#include <QDebug>
#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QScrollArea>
#include <QDesktopWidget>

#include "AnalyticHeightField.h"
#include "HeightField.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void onCharger();
    void onNoise();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    bool noiseFct;
    std::string noNoiseFilename;

    void Affiche(std::string filename = "../../data/noise.ppm");

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
