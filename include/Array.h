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
    vector2 getVertex(int x , int y)const;
    int getIndex(int x , int y)const{return x + y * sizeX;};
    void getGridIndex(const vector2& vec, int& x, int& y)const;
    int getSizeX() {return sizeX;}
    int getSizeY() {return sizeY;}
    int getSizeGridX() {return sizeGridX;}
    int getSizeGridY() {return sizeGridY;}
  protected:
    int sizeX, sizeY;
    double sizeGridX, sizeGridY;
};


#endif //MODELISATION_ARRAY_H
