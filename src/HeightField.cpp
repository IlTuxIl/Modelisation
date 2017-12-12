//
// Created by julien on 30/11/17.
//

#include <iostream>
#include <Image.h>
#include <Noise.h>
#include "HeightField.h"

void HeightField::noise(const vector2 &min, const vector2 &max, double zMin, double zMax, int _sizeX, int _sizeY) {

    Noise n;
    sizeX = _sizeX;
    sizeY = _sizeY;
    value = new double[sizeX * sizeY];
    xyMin = min;
    xyMax = max;
    sizeGridX = (getXMax() - getXMin()) / (sizeX -1);
    sizeGridY = (getYMax() - getYMin()) / (sizeY -1);

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            double newVal = zMin + ((n.At(vector2(j, i))+1)/2.0) * (zMax-zMin);
            value[getIndex(j,i)] = newVal;
        }
    }

}

void HeightField::load(std::string filename, const vector2 &min, const vector2 &max, double zMin, double zMax) {
    Image img(filename);
    sizeX = img.getWidth();
    sizeY = img.getHeight();
    value = new double[sizeX * sizeY];
    xyMin = min;
    xyMax = max;
    sizeGridX = (getXMax() - getXMin()) / (sizeX -1);
    sizeGridY = (getYMax() - getYMin()) / (sizeY -1);

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            double newVal = zMin + ((double)img.getValue(j, i)/255.0) * (zMax-zMin);
            value[getIndex(j,i)] = newVal;
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

Maillage HeightField::getMaillage() {
    Maillage ret;
    std::vector<float> vertex;
    std::vector<unsigned int> face;

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j) {

            float x = j * sizeGridX;
            float y = i * sizeGridY;
            float z = getHeight(getVertex(j,i));

            vertex.push_back(x);
            vertex.push_back(y);
            vertex.push_back(z);
        }
    }

    for(int i = 0; i < (sizeX-1); i++){
        int cptY = 0 ;
        int cptZ = 0;
        for(int j = 0; j < (sizeY-1); j++){
            int cptX = 0;
            cptZ++;
            for(int k = 0; k < 2; k++){
                face.push_back(j * sizeX + cptX + i);
                face.push_back(sizeX * cptZ + i);
                face.push_back(sizeX * cptY + i + 1);

                cptX++;
                if(k == 0)
                    cptY++;
            }
        }
    }

    ret.setNbIndiceFace(3);
    ret.setVertexBuffer(vertex);
    ret.setIndiceBuffer(face);
    return ret;
}

vector3 HeightField::getNormal(int x, int y) const {

    if (x >= sizeX && y >= sizeY && x < 0 && y < 0){
        std::cout << "HeightField getNormal : ATTENTION x,y hors du tableau" << std::endl;
        return vector3();
    }

    if(x > 0 && x < sizeX -1 && y > 0 && y < sizeY - 1) { // cas général

    }
    //      b
    //      |\
    //      | \
    //      a--c
    if(x == 0 && y == 0){ //cas bas gauche
        vector3 a(0        , 0        , value[0]);
        vector3 b(0        , sizeGridY, value[sizeX]);
        vector3 c(sizeGridX, 0        , value[1]);
        return ((c-a).cross(b-a)).normalize();
    }

    //      c--d
    //      |\ |
    //      | \|
    //      b--a
    if(x == sizeX-1 && y == 0){//cas bas droite
        vector3 a(sizeGridX * (x)  , 0, value[x]);
        vector3 b(sizeGridX * (x-1), 0, value[x-1]);
        vector3 c(sizeGridX * (x-1), 1, value[2*sizeX - 2]);
        vector3 d(sizeGridX * (x)  , 1, value[2*sizeX - 1]);

        vector3 abc((c-a).cross(b-a));
        vector3 acd((d-a).cross(c-a));
        return (abc * 0.5 + acd * 0.5).normalize();
    }
    //       b--a
    //        \ |
    //         \|
    //          c
    if(x == sizeX-1 && y == sizeY-1){
        vector3 a(sizeGridX * (sizeX-1), sizeGridY * (sizeY-1), value[x + sizeX * y]);
        vector3 b(sizeGridX * (sizeX-2), sizeGridY * (sizeY-1), value[x-1 + sizeX * y]);
        vector3 c(sizeGridX * (sizeX-1), sizeGridY * (sizeY-2), value[x + sizeX * (y-1)]);
        return ((b-a).cross(c-a)).normalize();
    }
    //      a--b
    //      |\ |
    //      | \|
    //      d--c
    if(x == 0 && y == sizeY-1){
        vector3 a(        0, sizeGridY * (y)  , value[sizeX * y]);
        vector3 b(sizeGridX, sizeGridY * (y)  , value[sizeX * y + 1]);
        vector3 c(sizeGridX, sizeGridY * (y-1), value[sizeX * (y-1) + 1]);
        vector3 d(        0, sizeGridY * (y-1), value[sizeX * (y-1)]);

        vector3 abc((c-a).cross(b-a));
        vector3 acd((d-a).cross(c-a));
        return (abc * 0.5 + acd * 0.5).normalize();
    }

    //    b
    //    |\
    //    a-c
    //    |\|
    //    e-d
    if(x == 0){
        vector3 a(0        , sizeGridY * (y)  , value[sizeX * y]);
        vector3 b(0        , sizeGridY * (y+1), value[sizeX * (y+1)]);
        vector3 c(sizeGridX, sizeGridY * (y)  , value[sizeX * y + 1]);
        vector3 d(sizeGridX, sizeGridY * (y-1), value[sizeX * (y-1) + 1]);
        vector3 e(0        , sizeGridY * (y-1), value[sizeX * (y-1)]);

        vector3 abc((c-a).cross(b-a));
        vector3 acd((d-a).cross(c-a));
        vector3 ade((e-a).cross(d-a));
        return (abc * 0.33 + acd * 0.33 + ade * 0.33).normalize();
    }

    //    c-b
    //    |\|
    //    d-a
    //     \|
    //      e
    if(x == sizeX -1){
        vector3 a(sizeGridX * (x)  , sizeGridY * (y), value[sizeX * y + x]);
        vector3 b(sizeGridX * (x)  , sizeGridY * (y+1), value[sizeX * (y+1) + x]);
        vector3 c(sizeGridX * (x-1), sizeGridY * (y+1), value[sizeX * (y+1) + x - 1]);
        vector3 d(sizeGridX * (x-1), sizeGridY * (y), value[sizeX * y + x - 1]);
        vector3 e(sizeGridX * (x)  , sizeGridY * (y-1), value[sizeX * (y-1) + x]);

        vector3 abc((b-a).cross(c-a));
        vector3 acd((c-a).cross(d-a));
        vector3 ade((d-a).cross(e-a));
        return (abc * 0.33 + acd * 0.33 + ade * 0.33).normalize();
    }
    //    c-d
    //    |\|\
    //    b-a-e
    if(y == 0){
        vector3 a(sizeGridX * (x)  , 0        , value[x]);
        vector3 b(sizeGridX * (x-1), 0        , value[x-1]);
        vector3 c(sizeGridX * (x-1), sizeGridY, value[sizeX + x - 1]);
        vector3 d(sizeGridX * (x)  , sizeGridY, value[sizeX + x]);
        vector3 e(sizeGridX * (x+1), 0        , value[x+1]);

        vector3 abc((c-a).cross(b-a));
        vector3 acd((d-a).cross(c-a));
        vector3 ade((e-a).cross(d-a));
        return (abc * 0.33 + acd * 0.33 + ade * 0.33).normalize();
    }

    //    b-a-e
    //     \|\|
    //      c-d
    if(y == sizeY-1){
        vector3 a(sizeGridX * (x)  , sizeGridY * (y)  , value[sizeX * y + x]);
        vector3 b(sizeGridX * (x-1), sizeGridY * (y)  , value[sizeX * y + x - 1]);
        vector3 c(sizeGridX * (x)  , sizeGridY * (y-1), value[sizeX * (y-1) + x]);
        vector3 d(sizeGridX * (x+1), sizeGridY * (y-1), value[sizeX * (y-1) + x + 1]);
        vector3 e(sizeGridX * (x+1), sizeGridY * (y)  , value[sizeX * y + x + 1]);

        vector3 abc((b-a).cross(c-a));
        vector3 acd((c-a).cross(d-a));
        vector3 ade((d-a).cross(e-a));
        return (abc * 0.33 + acd * 0.33 + ade * 0.33).normalize();
    }

    return vector3();
}






























