//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_LAYERFIELD_H
#define MODELISATION_LAYERFIELD_H


#include "Array.h"
#include "ScalarField.h"
#include "HeightField.h"

class LayerField : public Array{

public:
    LayerField(ScalarField* _bedRock, ScalarField* _sand, const Vector2& min, const Vector2& max, int sx, int sy);
    HeightField toHeightField(double zMin, double zMax);


protected:
    ScalarField* bedRock;
    ScalarField* sand;
};


#endif //MODELISATION_LAYERFIELD_H
