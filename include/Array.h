//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_ARRAY_H
#define MODELISATION_ARRAY_H


#include "Box.h"

class Array : public Box{
  public:
    Array() = default;
    Array(const vector2& min, const vector2& max, int nx, int ny) : Box(min, max), sizeX(nx), sizeY(ny){};
    vector2 getVertex(int x , int y);
    vector2 getIndex(int x , int y){return x + y * sizeX;};

    int getSizeX() {return sizeX;}
    int getSizeY() {return sizeY;}
  protected:
    int sizeX, sizeY;
};


#endif //MODELISATION_ARRAY_H
