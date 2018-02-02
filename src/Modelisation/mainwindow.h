#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QScrollArea>
#include <QDesktopWidget>

#include "AnalyticHeightField.h"
#include "HeightField.h"
#include "Route.h"

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
    void Affiche(std::string filename);

private:
    Ui::MainWindow *ui;
    void closeEvent (QCloseEvent * event);
};

#endif // MAINWINDOW_H
