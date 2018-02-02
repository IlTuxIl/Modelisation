#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget desktop;
    QRect surface_bureau = desktop.screenGeometry();

    w.setWindowTitle("[Modelisation de Terrains] Drainage, Vegetation et Routes");
    w.move(surface_bureau.width()/2 - w.width()/2, surface_bureau.height()/2 - w.height()/2);

    w.show();

    return a.exec();
}
