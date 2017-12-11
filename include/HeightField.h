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

    void load(std::string filename, const vector2& min, const vector2& max, double zMin, double zMax);
    void destroy();
    double getHeight(const vector2& v, interpolMethod method = BILINEAIRE)const;
    double getNormal(const vector2& v, interpolMethod method = BILINEAIRE)const;

    Maillage getMaillage();

    double interpolationTriangulaire(const vector2& v)const;
    double interpolationBilineaire(const vector2& v)const;
    double interpolationBicubique(const vector2& v)const;

protected:

};


#endif //MODELISATION_HEIGHTFIELD_H
