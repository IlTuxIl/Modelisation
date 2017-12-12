//
// Created by julien on 04/12/17.
//

#include <Image.h>
#include <cmath>
#include "ScalarField.h"

ScalarField::ScalarField(const Vector2 &min, const Vector2 &max, int _sizeX, int _sizeY) : Array(min, max, _sizeX,
                                                                                                 _sizeY) {
    values = new double(sizeX * sizeY);
}

ScalarField::~ScalarField() {
   // delete[] values;
}

double ScalarField::GradientNorm(int i, int j) const {

    Vector2 grad = Gradient(i,j);

    return sqrt(pow(grad.getX(), 2) + pow(grad.getY(), 2));
}

Vector2 ScalarField::Gradient(int i, int j) const {

    Vector2 n;
    Vector2 d = cellDiagonal();

    if(i == 0)
        n[0] = values[getIndex(i+1, j)]/d.getX();
    else if(i == sizeX)
        n[0] = values[getIndex(i-1, j)]/ d.getX();
    else
        n[0] = (values[getIndex(i+1, j)] - values[getIndex(i-1,j)]) / 2.0 * d.getX();

    if(j == 0)
        n[1] = values[getIndex(i, j+1)]/ d.getY();
    else if(j == sizeY)
        n[1] = values[getIndex(i, j-1)]/ d.getY();
    else
        n[1] = (values[getIndex(i, j+1)] - values[getIndex(i,j-1)]) / 2.0 * d.getY();

    return n;
}

void ScalarField::saveImg(std::string filename) {
    int* tmp = new int[sizeX * sizeY];
    for(int i = 0; i < sizeY * sizeX; ++i) {
        tmp[i] = (unsigned char) ((values[i] / 255.0) * 255);
    }
    Image img(filename, sizeX, sizeY, tmp);
    delete[] tmp;
}
