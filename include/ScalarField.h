//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_SCALARFIELD_H
#define MODELISATION_SCALARFIELD_H


#include "Array.h"

class ScalarField : public Array {
public:
    ScalarField() = default;
    ScalarField(const Vector2& min, const Vector2& max, int _sizeX, int _sizeY) ;
    ~ScalarField();

    void setValue(int x, int y, double value) {
        values[getIndex(x,y)] = value;
    }
    double getValue(int x, int y) const {
        return values[getIndex(x,y)];
    }

    double GradientNorm(int i, int j) const;
    Vector2 Gradient(int i, int j) const;
    void saveImg(std::string filename);

protected:
    double* values;
};


#endif //MODELISATION_SCALARFIELD_H

