//
// Created by julien on 30/11/17.
//

#ifndef MODELISATION_HEIGHTFIELD_H
#define MODELISATION_HEIGHTFIELD_H


#include <stack>
#include "Vector.h"
#include "Array.h"
#include "ScalarField.h"
#include "Maillage.h"
#include "Veget.h"

class HeightField : public ScalarField {

  public:
    HeightField() = default;
    HeightField(const Vector2& min, const Vector2& max, int _sizeX, int _sizeY) : ScalarField(min, max, _sizeX, _sizeY){} ;
    ScalarField Slope() const;
    ScalarField Drainage(double = 1.0) const;
    ScalarField Wetness(const ScalarField& slope, const ScalarField& drainage, int k) const;
    ScalarField PowerStream(const ScalarField& slope, const ScalarField& drainage) const;


    HeightField reSample(int _sizeX, int _sizeY);
//    void noise(const Vector2& min, const Vector2& max, double zMin, double zMax, int _sizeX, int _sizeY);
    void load(std::string filename, const Vector2& min, const Vector2& max, double zMin, double zMax);
    Vector3 getNormal(int x, int y)const;
    Maillage getMaillage();

  protected:
    void drainage(ScalarField& sf, int x) const;
    std::stack<int> getStack() const;
    bool max(int,int)const;

};


#endif //MODELISATION_HEIGHTFIELD_H
