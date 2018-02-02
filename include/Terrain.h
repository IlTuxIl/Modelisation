//
// Created by julien on 16/01/18.
//

#ifndef MODELISATION_TERRAIN_H
#define MODELISATION_TERRAIN_H

#include "HeightField.h"

class Foret;
class Terrain {
public:
    Terrain() = default;
    Terrain(const HeightField& h);
    Foret Vegetation(double canope, int nbIter = 10000);

    ScalarField getSlope() const {return slope;}
    ScalarField getDrainage() const {return drainage;}
    ScalarField getWetness() const {return wetness;}
    ScalarField getPowerStream() const {return powerStream;}
    HeightField getHeightMap() const {return height;}

    Array getArray() const {return height.getArray();};


protected:
    ScalarField slope, drainage, wetness, powerStream;
    HeightField height;
};

#include "Foret.h"


#endif //MODELISATION_TERRAIN_H
