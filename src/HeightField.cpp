//
// Created by julien on 30/11/17.
//

#include <iostream>
#include <Image.h>
#include <algorithm>
#include "HeightField.h"

ScalarField HeightField::Slope() const {

    ScalarField sf(xyMin, xyMax,sizeX,sizeY);

    for(int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            sf.setValue(j, i, GradientNorm(j,i));
        }
    }

    return sf;
}

ScalarField HeightField::Drainage(double w) const {
    ScalarField ret(xyMin, xyMax, sizeX, sizeY);
    std::stack<int> ordre = getStack();

    for(int i = 0; i < values.size(); ++i)
        ret.setValue(i, w);

    while(!ordre.empty()){
        int id = ordre.top();
        ordre.pop();

        drainage(ret, id);
    }

    return ret;
}

ScalarField HeightField::PowerStream(const ScalarField& slope, const ScalarField& drainage) const {
    ScalarField ret(xyMin, xyMax, sizeX, sizeY);

    for(int i = 0; i < sizeY; ++i)
        for(int j = 0; j < sizeX; ++j)
            ret.setValue(j, i, slope.getValue(j,i) * pow(drainage.getValue(j, i), 0.5));

    return ret;
}

HeightField HeightField::reSample(int _sizeX, int _sizeY) {
    HeightField ret(xyMin, xyMax, _sizeX, _sizeY);

    ret.values.reserve(sizeX * sizeY);;

    for(int i = 0; i < ret.sizeY; ++i) {
        for (int j = 0; j < ret.sizeX; ++j) {
            ret.values.push_back(getHeight(ret.getVertex(j, i)));
        }
    }

    return ret;
}
//void HeightField::noise(const Vector2 &min, const Vector2 &max, double zMin, double zMax, int _sizeX, int _sizeY) {
//
//    Noise n;
//    sizeX = _sizeX;
//    sizeY = _sizeY;
//    values.reserve(sizeX * sizeY);
//    xyMin = min;
//    xyMax = max;
//    sizeGridX = (getXMax() - getXMin()) / (sizeX -1);
//    sizeGridY = (getYMax() - getYMin()) / (sizeY -1);
//
//    for(int i = 0; i < sizeY; ++i){
//        for(int j = 0; j < sizeX; ++j){
//            double newVal = zMin + ((n.At(Vector2(j, i))+1)/2.0) * (zMax-zMin);
//            values[getIndex(j,i)] = newVal;
//        }
//    }
//
//}

void HeightField::load(std::string filename, const Vector2 &min, const Vector2 &max, double zMin, double zMax) {
    Image img(filename);
    sizeX = img.getWidth();
    sizeY = img.getHeight();
    values.reserve(sizeX * sizeY);
    xyMin = min;
    xyMax = max;
    sizeGridX = (getXMax() - getXMin()) / (sizeX -1);
    sizeGridY = (getYMax() - getYMin()) / (sizeY -1);

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            double newVal = zMin + ((double)img.getValue(j, i)/255.0) * (zMax-zMin);
            values.push_back(newVal);
        }
    }

}

void HeightField::destroy() {
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

Vector3 HeightField::getNormal(int x, int y) const {

    if (x >= sizeX && y >= sizeY && x < 0 && y < 0){
        std::cout << "HeightField getNormal : ATTENTION x,y hors du tableau" << std::endl;
        return Vector3();
    }

    if(x > 0 && x < sizeX -1 && y > 0 && y < sizeY - 1) { // cas général

    }
    //      b
    //      |\
    //      | \
    //      a--c
    if(x == 0 && y == 0){ //cas bas gauche
        Vector3 a(0        , 0        , values[0]);
        Vector3 b(0        , sizeGridY, values[sizeX]);
        Vector3 c(sizeGridX, 0        , values[1]);
        return ((c-a).cross(b-a)).normalize();
    }

    //      c--d
    //      |\ |
    //      | \|
    //      b--a
    if(x == sizeX-1 && y == 0){//cas bas droite
        Vector3 a(sizeGridX * (x)  , 0, values[x]);
        Vector3 b(sizeGridX * (x-1), 0, values[x-1]);
        Vector3 c(sizeGridX * (x-1), 1, values[2*sizeX - 2]);
        Vector3 d(sizeGridX * (x)  , 1, values[2*sizeX - 1]);

        Vector3 abc((c-a).cross(b-a));
        Vector3 acd((d-a).cross(c-a));
        return (abc * 0.5 + acd * 0.5).normalize();
    }
    //       b--a
    //        \ |
    //         \|
    //          c
    if(x == sizeX-1 && y == sizeY-1){
        Vector3 a(sizeGridX * (sizeX-1), sizeGridY * (sizeY-1), values[x + sizeX * y]);
        Vector3 b(sizeGridX * (sizeX-2), sizeGridY * (sizeY-1), values[x-1 + sizeX * y]);
        Vector3 c(sizeGridX * (sizeX-1), sizeGridY * (sizeY-2), values[x + sizeX * (y-1)]);
        return ((b-a).cross(c-a)).normalize();
    }
    //      a--b
    //      |\ |
    //      | \|
    //      d--c
    if(x == 0 && y == sizeY-1){
        Vector3 a(        0, sizeGridY * (y)  , values[sizeX * y]);
        Vector3 b(sizeGridX, sizeGridY * (y)  , values[sizeX * y + 1]);
        Vector3 c(sizeGridX, sizeGridY * (y-1), values[sizeX * (y-1) + 1]);
        Vector3 d(        0, sizeGridY * (y-1), values[sizeX * (y-1)]);

        Vector3 abc((c-a).cross(b-a));
        Vector3 acd((d-a).cross(c-a));
        return (abc * 0.5 + acd * 0.5).normalize();
    }

    //    b
    //    |\
    //    a-c
    //    |\|
    //    e-d
    if(x == 0){
        Vector3 a(0        , sizeGridY * (y)  , values[sizeX * y]);
        Vector3 b(0        , sizeGridY * (y+1), values[sizeX * (y+1)]);
        Vector3 c(sizeGridX, sizeGridY * (y)  , values[sizeX * y + 1]);
        Vector3 d(sizeGridX, sizeGridY * (y-1), values[sizeX * (y-1) + 1]);
        Vector3 e(0        , sizeGridY * (y-1), values[sizeX * (y-1)]);

        Vector3 abc((c-a).cross(b-a));
        Vector3 acd((d-a).cross(c-a));
        Vector3 ade((e-a).cross(d-a));
        return (abc * 0.33 + acd * 0.33 + ade * 0.33).normalize();
    }

    //    c-b
    //    |\|
    //    d-a
    //     \|
    //      e
    if(x == sizeX -1){
        Vector3 a(sizeGridX * (x)  , sizeGridY * (y), values[sizeX * y + x]);
        Vector3 b(sizeGridX * (x)  , sizeGridY * (y+1), values[sizeX * (y+1) + x]);
        Vector3 c(sizeGridX * (x-1), sizeGridY * (y+1), values[sizeX * (y+1) + x - 1]);
        Vector3 d(sizeGridX * (x-1), sizeGridY * (y), values[sizeX * y + x - 1]);
        Vector3 e(sizeGridX * (x)  , sizeGridY * (y-1), values[sizeX * (y-1) + x]);

        Vector3 abc((b-a).cross(c-a));
        Vector3 acd((c-a).cross(d-a));
        Vector3 ade((d-a).cross(e-a));
        return (abc * 0.33 + acd * 0.33 + ade * 0.33).normalize();
    }
    //    c-d
    //    |\|\
    //    b-a-e
    if(y == 0){
        Vector3 a(sizeGridX * (x)  , 0        , values[x]);
        Vector3 b(sizeGridX * (x-1), 0        , values[x-1]);
        Vector3 c(sizeGridX * (x-1), sizeGridY, values[sizeX + x - 1]);
        Vector3 d(sizeGridX * (x)  , sizeGridY, values[sizeX + x]);
        Vector3 e(sizeGridX * (x+1), 0        , values[x+1]);

        Vector3 abc((c-a).cross(b-a));
        Vector3 acd((d-a).cross(c-a));
        Vector3 ade((e-a).cross(d-a));
        return (abc * 0.33 + acd * 0.33 + ade * 0.33).normalize();
    }

    //    b-a-e
    //     \|\|
    //      c-d
    if(y == sizeY-1){
        Vector3 a(sizeGridX * (x)  , sizeGridY * (y)  , values[sizeX * y + x]);
        Vector3 b(sizeGridX * (x-1), sizeGridY * (y)  , values[sizeX * y + x - 1]);
        Vector3 c(sizeGridX * (x)  , sizeGridY * (y-1), values[sizeX * (y-1) + x]);
        Vector3 d(sizeGridX * (x+1), sizeGridY * (y-1), values[sizeX * (y-1) + x + 1]);
        Vector3 e(sizeGridX * (x+1), sizeGridY * (y)  , values[sizeX * y + x + 1]);

        Vector3 abc((b-a).cross(c-a));
        Vector3 acd((c-a).cross(d-a));
        Vector3 ade((d-a).cross(e-a));
        return (abc * 0.33 + acd * 0.33 + ade * 0.33).normalize();
    }

    return Vector3();
}

bool HeightField::max(int a, int b) const {
    return values[a] > values[b];
}

std::stack<int> HeightField::getStack() const {

    std::vector<int> v;
    std::stack<int> ret;

    for(int i = 0; i < values.size(); ++i)
        v.push_back(i);

    std::sort(v.begin(), v.end(), Trie(*this));

    for(int i : v)
        ret.push(i);

    return ret;
}

void HeightField::drainage(ScalarField &sf, int id) const {
    int y = id / sf.getSizeX();
    int x = id % sf.getSizeX();

    float somme = 0;

    for(int i = y-1; i <= y+1; ++i){
        for(int j = x-1; j <= x+1; ++j) {
            if(checkBound(j, i)) {
                if (i == y && j == x || values[getIndex(j, i)] >= values[id])
                    continue;
                somme += values[id] - values[getIndex(j, i)];
            }
        }
    }

    for(int i = y-1; i <= y+1; ++i){
        for(int j = x-1; j <= x+1; ++j) {
            if(checkBound(j, i)) {

                if (i == y && j == x || values[getIndex(j, i)] >= values[id])
                    continue;

                double tmp = sf.getValue(j, i) + (values[id] - values[getIndex(j, i)]) / somme;
                sf.setValue(j, i, tmp);
            }
        }
    }

}



























