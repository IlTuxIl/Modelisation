#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("[Modelisation] Generation de terrains avec aire de drainage, vegetation et routes - Fleckinger et Breton");
    w.show();

    return a.exec();
}
