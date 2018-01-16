#include "Results.h"
//#include <QImage>

void Results::SetImage(const std::string & nomDuFichier)
{
    double x = 1000.0f;
    double y = 1000.0f;

    HeightField hf;
    hf.load(nomDuFichier, Vector2(0,0), Vector2(x,y), 0, 100.0);

    *img_hauteur = hf.saveImg(nomDuFichier + "_height");

    // On calcule les pente
    /*ScalarField s = hf.Slope();
    *img_pente = s.saveImg(nomDuFichier + "_slope");*/

    // On calcule l'eau
    //img_eau =
}
