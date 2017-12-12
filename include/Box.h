//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_BOX_H
#define MODELISATION_BOX_H


#include "Vector.h"

class Box {
  public:
    Box() = default;
    Box(const Vector2& min, const Vector2& max);

    Vector2 getCorner(int i);
    double getXMin()const{return xyMin.getX();}
    double getXMax()const{return xyMax.getX();}
    double getYMin()const{return xyMin.getY();}
    double getYMax()const{return xyMax.getY();}

protected:
    Vector2 xyMin;
    Vector2 xyMax;

};


#endif //MODELISATION_BOX_H
