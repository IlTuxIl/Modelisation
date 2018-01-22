#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("[Modelisation de Terrains] Drainage, Vegetation et Routes");
    w.show();

    return a.exec();
}
