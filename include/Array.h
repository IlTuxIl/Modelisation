//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_ARRAY_H
#define MODELISATION_ARRAY_H


#include "Box.h"

class Array : public Box{
  public:
    Array() = default;
    Array(const Vector2& min, const Vector2& max, int nx, int ny) : Box(min, max), sizeX(nx), sizeY(ny){};
    Vector2 getVertex(int x , int y)const;
    int getIndex(int x , int y)const{return x + y * sizeX;};
    void getGridIndex(const Vector2& vec, int& x, int& y)const;
    int getSizeX() const {return sizeX;}
    int getSizeY() const {return sizeY;}
    bool checkBound(int x, int y) const {return x >= 0 && x < sizeX && y >= 0 && y < sizeY;};

    Array getArray()const{return *this;}
    void setSizeGridX(double v){sizeGridX = v;}
    void setSizeGridY(double v){sizeGridY = v;}

    Vector2 getRandPos()const ;
    int getSizeGridX() const {return sizeGridX;}
    int getSizeGridY() const {return sizeGridY;}
    Vector2 cellDiagonal() const
    { Vector2 d = xyMax-xyMin; return Vector2(d.getX()/(sizeX-1), d.getY()/(sizeY-1)); }

  protected:
    int sizeX, sizeY;
    double sizeGridX, sizeGridY;
};


#endif //MODELISATION_ARRAY_H
