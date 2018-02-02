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
    Foret() = default;
    Foret(std::string filename, Terrain& t);
    Foret(std::vector<Vector2> spawn, Terrain& t, double angle = 0.8, double minWet = 0.2f, double maxWet = 1.0f);
    void simule();
    void saveForet(std::string filename)const;
    void loadForet(std::string filename);
    Maillage toMaillage() const;
    ScalarField toScalar();
protected:
    void computeSpacialisation();
    void addSpacialisation(int x, int y, const Veget& v);
    void delSpacialisation(int x, int y, int id);

    Terrain* terrain;
    std::vector<Veget> veget;
    Array array;
    std::vector<std::vector<Veget>> densiteVeget;
};


#endif //MODELISATION_FORET_H
