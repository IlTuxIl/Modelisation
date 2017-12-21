//
// Created by julien on 30/11/17.
//

#ifndef MODELISATION_HEIGHTFIELD_H
#define MODELISATION_HEIGHTFIELD_H


#include "Vector.h"
#include "Array.h"
#include "ScalarField.h"
#include "Maillage.h"


class HeightField : public ScalarField {

  public:
    HeightField() = default;
    HeightField(const Vector2& min, const Vector2& max, int _sizeX, int _sizeY) : ScalarField(min, max, _sizeX, _sizeY){} ;
    ScalarField Slope() const;
    HeightField reSample(int _sizeX, int _sizeY);
    void noise(const Vector2& min, const Vector2& max, double zMin, double zMax, int _sizeX, int _sizeY);
    void load(std::string filename, const Vector2& min, const Vector2& max, double zMin, double zMax);
    void destroy();
    Vector3 getNormal(int x, int y)const;
    Maillage getMaillage();


protected:

};


#endif //MODELISATION_HEIGHTFIELD_H
