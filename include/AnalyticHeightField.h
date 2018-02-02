//
// Created by julien on 12/12/17.
//

#ifndef MODELISATION_ANALYTICHEIGHTMAP_H
#define MODELISATION_ANALYTICHEIGHTMAP_H


#include "HeightField.h"

class AnalyticHeightField : public HeightField {
public:
    AnalyticHeightField(Vector2 min, Vector2 max, int _sizeX, int _sizeY, std::vector<double> freq, std::vector<double> ampli);
    void retourne();
};


#endif //MODELISATION_ANALYTICHEIGHTMAP_H
