//
// Created by julien on 30/11/17.
//

#include <iostream>
#include <Image.h>
#include "HeightField.h"

void HeightField::load(std::string filename, const vector2 &min, const vector2 &max, double zMin, double zMax) {


}

double HeightField::getHeight(const vector2 &v, interpolMethod method) const {
    if (v.getX() >= width && v.getY() >= height && v.getX() < 0 && v.getY() < 0){
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

double HeightField::interpolationBilineaire(const vector2& v)const{
    return 1;
}

double HeightField::interpolationBicubique(const vector2& v)const{
    return 2;
}