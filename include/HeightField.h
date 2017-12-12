//
// Created by julien on 30/11/17.
//

#ifndef MODELISATION_HEIGHTFIELD_H
#define MODELISATION_HEIGHTFIELD_H


#include "Vector.h"
#include "Array.h"
#include "ScalarField.h"
#include "Maillage.h"

enum interpolMethod{TRIANGULAIRE, BILINEAIRE, BICUBIQUE};

class HeightField : public ScalarField {

  public:
    ScalarField Slope() const;
    void noise(const Vector2& min, const Vector2& max, double zMin, double zMax, int _sizeX, int _sizeY);
    void load(std::string filename, const Vector2& min, const Vector2& max, double zMin, double zMax);
    void destroy();
    double getHeight(const Vector2& v, interpolMethod method = BILINEAIRE)const;
    Vector3 getNormal(int x, int y)const;

    Maillage getMaillage();

    double interpolationTriangulaire(const Vector2& v)const;
    double interpolationBilineaire(const Vector2& v)const;
    double interpolationBicubique(const Vector2& v)const;

protected:

};


#endif //MODELISATION_HEIGHTFIELD_H
