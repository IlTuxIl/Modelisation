//
// Created by julien on 04/12/17.
//

#include <iostream>
#include "Array.h"


vector2 Array::getVertex(int i, int j) {
    vector2 ret;

    if(i > sizeX-1 || j > sizeY-1)
        std::cout << "Array : ATTENTION index hors tableau" << std::endl;

    ret.setX(xyMin.getX() + ((xyMax.getX() - xyMin.getX()) / (sizeX - 1)) * i);
    ret.setY(xyMin.getY() + ((xyMax.getY() - xyMin.getY()) / (sizeY - 1)) * j);
    return ret;
}
