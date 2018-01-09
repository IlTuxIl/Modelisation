#ifndef RESULTS
#define RESULTS

#include "HeightField.h"
#include "Image.h"
#include <set>

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
