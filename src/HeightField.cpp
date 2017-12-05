//
// Created by julien on 30/11/17.
//

#include <iostream>
#include <Image.h>
#include "HeightField.h"

void HeightField::load(std::string filename, const vector2 &min, const vector2 &max, double zMin, double zMax) {
    Image img(filename);
    sizeX = img.getHeight();
    sizeY = img.getWidth();
    value = new double[sizeX * sizeY];
    xyMin = min;
    xyMax = max;
    sizeGridX = (getXMax() - getXMin()) / sizeX;
    sizeGridY = (getYMax() - getYMin()) / sizeY;
    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            double newVal = zMin + ((double)img.getValue(j, i)/255.0) * (zMax-zMin);
            value[i * sizeX + j] = newVal;
        }
    }
}

double HeightField::getHeight(const vector2 &v, interpolMethod method) const {
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

double HeightField::interpolationTriangulaire(const vector2& v)const{
    return 0;
}

double HeightField::interpolationBilineaire(const vector2& vec)const{
    int xGrid, yGrid;
    vector2 tmp(vec);
    getGridIndex(vec, xGrid, yGrid);

    double x0y0 = value[xGrid + yGrid*sizeX];
    double x1y0 = value[xGrid + 1 + yGrid*sizeX];
    double x0y1 = value[xGrid + (yGrid+1)*sizeX];
    double x1y1 = value[xGrid + 1 + (yGrid+1)*sizeX];

    tmp[0] = tmp[0] - (xGrid * sizeGridX);
    tmp[1] = tmp[1] - (yGrid * sizeGridY);

    double U = tmp.getX() / sizeGridX;
    double V = tmp.getY() / sizeGridY;

    return (1-U) * (1-V) * x0y0 +
            (1-U) * (V) * x0y1 +
            (U) * (1-V) * x1y0 +
            (U) * (V) * x1y1;
}

double HeightField::interpolationBicubique(const vector2& v)const{
    return 2;
}

void HeightField::destroy() {
    delete[] value;
}
