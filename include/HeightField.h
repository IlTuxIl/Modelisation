//
// Created by julien on 30/11/17.
//

#ifndef MODELISATION_HEIGHTFIELD_H
#define MODELISATION_HEIGHTFIELD_H


#include "Vector.h"

enum interpolMethod{TRIANGULAIRE, BILINEAIRE, BICUBIQUE};

class HeightField {

  public:
    double getIndex(int x, int y)const{return x + y * width;};
    double getHeight(const vector2& v, interpolMethod method = BILINEAIRE)const;

    double interpolationTriangulaire(const vector2& v)const;
    double interpolationBilineaire(const vector2& v)const;
    double interpolationBicubique(const vector2& v)const;

protected:

    double* value = NULL;
    int  height = -1;
    int width = -1;

};


#endif //MODELISATION_HEIGHTFIELD_H
