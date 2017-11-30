//
// Created by julien on 30/11/17.
//

#ifndef MODELISATION_HEIGHTFIELD_H
#define MODELISATION_HEIGHTFIELD_H


#include "Vector.h"

class HeightField {
  public:
    double getIndex(int x, int y)const{return x + y * width;};
    double getHeight(const vector2& v)const;
  protected:
    double* value;
    int height, width;
};


#endif //MODELISATION_HEIGHTFIELD_H
