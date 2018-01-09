#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Results.h"

#include <QMainWindow>
#include <QtOpenGL/QGLWidget>
#include <QDebug>
#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QScrollArea>

#include <QDesktopWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void onCharger();
    void onReset();

    //void onNoise();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void Affiche();

private:
    Ui::MainWindow *ui;
    Results * results;
};

#endif // MAINWINDOW_H
