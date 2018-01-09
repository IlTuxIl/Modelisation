//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_SCALARFIELD_H
#define MODELISATION_SCALARFIELD_H

#include <cmath>
#include <vector>
#include<../../include/Image.h>
#include "Array.h"

enum interpolMethod{TRIANGULAIRE, BILINEAIRE, BICUBIQUE};

class ScalarField : public Array {
public:
    ScalarField() = default;
    ScalarField(const Vector2& min, const Vector2& max, int _sizeX, int _sizeY) ;
    ~ScalarField();

    void addValue(double value) {
        values.push_back(value);
    }

    void setValue(int x, int y, double value) {
        values[getIndex(x,y)] = value;
    }
    double getValue(int x, int y) const {
        return values[getIndex(x,y)];
    }

    double GradientNorm(int i, int j) const;
    Vector2 Gradient(int i, int j) const;
    Image saveImg(std::string filename);
    void readImg(std::string filename);


    double getHeight(const Vector2& v, interpolMethod method = BILINEAIRE)const;
    double interpolationTriangulaire(const Vector2& v)const;
    double interpolationBilineaire(const Vector2& v)const;
    double interpolationBicubique(const Vector2& v)const;


protected:
    std::vector<double> values;
};


#endif //MODELISATION_SCALARFIELD_H

