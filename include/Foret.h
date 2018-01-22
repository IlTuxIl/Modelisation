//
// Created by julien on 16/01/18.
//

#ifndef MODELISATION_FORET_H
#define MODELISATION_FORET_H


#include "Box.h"
#include "Veget.h"
#include "Terrain.h"
#include "ScalarField.h"
#include <vector>

class Foret {
public:
    Foret(std::vector<Vector2> spawn, const Terrain& t, double angle = 0.8);
    ScalarField toScalar();
protected:
    std::vector<Veget> veget;
    Array array;
};


#endif //MODELISATION_FORET_H
