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
    LayerField(ScalarField* _bedRock, ScalarField* _sand);

    HeightField toHeightField();


protected:
    ScalarField* bedRock;
    ScalarField* sand;
};


#endif //MODELISATION_LAYERFIELD_H
