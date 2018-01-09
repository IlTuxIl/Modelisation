#ifndef RESULTS
#define RESULTS

#include <../../include/HeightField.h>
#include <QString>
#include <QImage>
#include <set>

class Image;
class Results{

public:
    Image * img_hauteur;
    Image * img_pente;
    Image * img_eau;

public:
    Results(){}
    Results(Image img);
    ~Results(){}

    void SetImage(const std::string & nomDuFichier);
};

#endif // RESULTS
