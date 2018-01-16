//
// Created by julien on 04/12/17.
//

#include <iostream>
#include "LayerField.h"

LayerField::LayerField(ScalarField *_bedRock, ScalarField *_sand, const Vector2& min, const Vector2& max, int _sizeX, int _sizeY) : Array(min, max, _sizeX, _sizeY) {
    sizeGridX = (getXMax() - getXMin()) / (sizeX - 1);
    sizeGridY = (getYMax() - getYMin()) / (sizeY - 1);
    bedRock = _bedRock;
    sand = _sand;

    bedRock->setMin(min);
    bedRock->setMax(max);

    bedRock->setSizeGridX((getXMax() - getXMin()) / (bedRock->getSizeX() - 1));
    bedRock->setSizeGridY((getYMax() - getYMin()) / (bedRock->getSizeY() - 1));

    sand->setMin(min);
    sand->setMax(max);

    sand->setSizeGridX((getXMax() - getXMin()) / (sand->getSizeX() - 1));
    sand->setSizeGridY((getYMax() - getYMin()) / (sand->getSizeY() - 1));
}

HeightField LayerField::toHeightField(double zMin, double zMax) {

    HeightField ret(xyMin, xyMax, sizeX, sizeY);

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){

            double hBedRock = bedRock->getHeight(getVertex(j,i));
            double hSand = sand->getHeight(getVertex(j,i));

            ret.setValue(j, i, zMin + ((hSand + hBedRock) / 510) * zMax);
        }
    }


    return ret;
}
