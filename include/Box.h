//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_BOX_H
#define MODELISATION_BOX_H


#include "Vector.h"

class Box {
  public:
    Box() = default;
    Box(const vector2& min, const vector2& max);

    vector2 getCorner(int i);
    double getXMin(){return xyMin.getX();}
    double getXMax(){return xyMax.getX();}
    double getYMin(){return xyMin.getY();}
    double getYMax(){return xyMax.getY();}

protected:
    vector2 xyMin;
    vector2 xyMax;

};


#endif //MODELISATION_BOX_H
