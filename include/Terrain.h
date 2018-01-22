//
// Created by julien on 16/01/18.
//

#ifndef MODELISATION_TERRAIN_H
#define MODELISATION_TERRAIN_H

#include "HeightField.h"

class Foret;
class Terrain {
public:
    Terrain(const HeightField& h);
    Foret Vegetation(double canope, int nbIter = 10000) const;

    ScalarField getSlope() const {return slope;}
    ScalarField getDrainage() const {return drainage;}
    ScalarField getWetness() const {return wetness;}
    HeightField getHeight() const {return height;}

    Array getArray() const {return height.getArray();};


protected:
    ScalarField slope, drainage, wetness;
    HeightField height;
};

#include "Foret.h"


#endif //MODELISATION_TERRAIN_H
