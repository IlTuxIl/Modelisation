//
// Created by julien on 04/12/17.
//

#include <iostream>
#include "Array.h"


Vector2 Array::getVertex(int i, int j) const {
    Vector2 ret;

    if(i > sizeX-1 || j > sizeY-1)
        std::cout << "Array : ATTENTION index hors tableau" << std::endl;

    ret.setX(xyMin.getX() + (sizeGridX) * (i));
    ret.setY(xyMin.getY() + (sizeGridY) * (j));
    return ret;
}

Vector2 Array::getRandPos() const{

    double p1 = (double) rand() / RAND_MAX;
    double p2 = (double) rand() / RAND_MAX;

    double x = p1 * (getXMax()-getXMin()) + getXMin();
    double y = p2 * (getYMax()-getYMin()) + getYMin();

    return Vector2(x, y);
}

void Array::getGridIndex(const Vector2 &vec, int &x, int &y) const {
    //ATTENTION FORMULE PAS SUR
    x = (vec.getX() - xyMin.getX()) / (xyMax.getX() - xyMin.getX()) * (sizeX - 1);
    y = (vec.getY() - xyMin.getY()) / (xyMax.getY() - xyMin.getY()) * (sizeY - 1);
}
