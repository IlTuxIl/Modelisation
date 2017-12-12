//
// Created by julien on 04/12/17.
//

#include <iostream>
#include "Box.h"

Box::Box(const Vector2 &min, const Vector2 &max) {
    xyMin = min;
    xyMax = max;
}

Vector2 Box::getCorner(int i) {
    switch (i){
        case 0:
            return Vector2(xyMin.getX(), xyMax.getY());
        case 1:
            return Vector2(xyMax.getX(), xyMax.getY());
        case 2:
            return Vector2(xyMin.getX(), xyMin.getY());
        case 3:
            return Vector2(xyMax.getX(), xyMin.getY());
        default:
            std::cout << "Box : ATTENTION i > 3" << std::endl;
    }
}

