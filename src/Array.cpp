//
// Created by julien on 04/12/17.
//

#include <iostream>
#include "Array.h"


vector2 Array::getVertex(int i, int j) const {
    vector2 ret;

    if(i > sizeX-1 || j > sizeY-1)
        std::cout << "Array : ATTENTION index hors tableau" << std::endl;

    ret.setX(xyMin.getX() + (sizeGridX) * i);
    ret.setY(xyMin.getY() + (sizeGridY) * j);
    return ret;
}

void Array::getGridIndex(const vector2 &vec, int &x, int &y) const {
    //ATTENTION FORMULE PAS SUR
    x = (vec.getX() - xyMin.getY()) / (xyMax.getX() - xyMin.getX()) * sizeX - 1;
    y = (vec.getY() - xyMin.getY()) / (xyMax.getY() - xyMin.getY()) * sizeY - 1;
}
