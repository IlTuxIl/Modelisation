//
// Created by julien on 04/12/17.
//

#include <Image.h>
#include <cmath>
#include "ScalarField.h"

ScalarField::ScalarField(const Vector2 &min, const Vector2 &max, int _sizeX, int _sizeY) : Array(min, max, _sizeX,
                                                                                                 _sizeY) {
    values.reserve(sizeX * sizeY);
    sizeGridX = (getXMax() - getXMin()) / (sizeX - 1);
    sizeGridY = (getYMax() - getYMin()) / (sizeY - 1);
}

ScalarField::~ScalarField() {
}

double ScalarField::GradientNorm(int i, int j) const {

    Vector2 grad = Gradient(i,j);

    return sqrt(pow(grad.getX(), 2) + pow(grad.getY(), 2));
}

Vector2 ScalarField::Gradient(int i, int j) const {

    Vector2 n;
    Vector2 d = cellDiagonal();

    if(i == 0)
        n[0] = (values[getIndex(i+1, j)] - values[getIndex(i, j)])   / (2.0 * d.getX());
    else if(i == sizeX-1)
        n[0] = (values[getIndex(i, j)]   - values[getIndex(i-1, j)]) / (2.0 * d.getX());
    else
        n[0] = (values[getIndex(i+1, j)] - values[getIndex(i-1,j)])  / (2.0 * d.getX());

    if(j == 0)
        n[1] = (values[getIndex(i, j+1)] - values[getIndex(i, j)])   / (2.0 * d.getY());
    else if(j == sizeY-1)
        n[1] = (values[getIndex(i, j)]   - values[getIndex(i, j-1)]) / (2.0 * d.getY());
    else
        n[1] = (values[getIndex(i, j+1)] - values[getIndex(i,j-1)])  / (2.0 * d.getY());

    return n;
}

void ScalarField::saveImg(std::string filename) {
    std::vector<int> tmp;
    tmp.reserve(sizeX * sizeY);
    double max = 0.0;

    for(double v : values) if(v > max) max=v;

    for(int i = 0; i < sizeY * sizeX; ++i) {
        tmp[i] = (unsigned char) (((values[i])/max) * 255);
    }
    Image img(filename, sizeX, sizeY, tmp.data());
}

void ScalarField::readImg(std::string filename) {
    Image img(filename);
    sizeX = img.getWidth();
    sizeY = img.getHeight();

    xyMin = Vector2(0,0);
    xyMax = Vector2(sizeX, sizeY);

    values.reserve(sizeX * sizeY);
    sizeGridX = (getXMax() - getXMin()) / (sizeX -1);
    sizeGridY = (getYMax() - getYMin()) / (sizeY -1);

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            double newVal = ((double)img.getValue(j, i));
            values.push_back(newVal);
        }
    }
}


double ScalarField::getHeight(const Vector2 &v, interpolMethod method) const {
    if (v.getX() >= sizeX && v.getY() >= sizeY && v.getX() < 0 && v.getY() < 0){
        std::cout << "HeightField : ATTENTION v hors du tableau" << std::endl;
        return 0.0;
    }

    switch (method){
        case TRIANGULAIRE:
            return interpolationTriangulaire(v);
        case BILINEAIRE:
            return interpolationBilineaire(v);
        case BICUBIQUE:
            return interpolationBicubique(v);
    }
}

double ScalarField::interpolationTriangulaire(const Vector2& v)const{
    return 0;
}

double ScalarField::interpolationBilineaire(const Vector2& vec)const{
    int xGrid, yGrid;
    Vector2 tmp(vec);
    getGridIndex(vec, xGrid, yGrid);


    double x0y0 = values[xGrid + yGrid*sizeX];
    double x1y0 = values[xGrid + 1 + yGrid*sizeX];
    double x0y1 = values[xGrid + (yGrid+1)*sizeX];
    double x1y1 = values[xGrid + 1 + (yGrid+1)*sizeX];

    tmp[0] = tmp[0] - (xGrid * sizeGridX);
    tmp[1] = tmp[1] - (yGrid * sizeGridY);

    double U = tmp.getX() / sizeGridX;
    double V = tmp.getY() / sizeGridY;

    return (1-U) * (1-V) * x0y0 +
           (1-U) * (V) * x0y1 +
           (U) * (1-V) * x1y0 +
           (U) * (V) * x1y1;
}

double ScalarField::interpolationBicubique(const Vector2& v)const{
    return 2;
}

