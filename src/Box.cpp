//
// Created by julien on 04/12/17.
//

#include <iostream>
#include "Box.h"

Box::Box(const vector2 &min, const vector2 &max) {
    xyMin = min;
    xyMax = max;
}

vector2 Box::getCorner(int i) {
    switch (i){
        case 0:
            return vector2(xyMin.getX(), xyMax.getY());
        case 1:
            return vector2(xyMax.getX(), xyMax.getY());
        case 2:
            return vector2(xyMin.getX(), xyMin.getY());
        case 3:
            return vector2(xyMax.getX(), xyMin.getY());
        default:
            std::cout << "Box : ATTENTION i > 3" << std::endl;
    }
}

