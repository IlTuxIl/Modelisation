//
// Created by julien on 30/10/17.
//

#include "Maillage.h"

void GeoLib::Maillage::setNbIndiceFace(int v) {
    nbIndicesFace = v;
}

void GeoLib::Maillage::setVertexBuffer(std::vector<float> &p) {
    vertex = p;
}

void GeoLib::Maillage::setIndiceBuffer(const std::vector<unsigned int> &p) {
    indice = p;
}

int GeoLib::Maillage::getNbIndiceFace() const {
    return nbIndicesFace;
}

std::vector<float> GeoLib::Maillage::getVertex() {

//    std::vector<float> ret;
//    ret.reserve(vertex.size() * 3);
//
//    for(vector3 s : vertex.getVector()){
//        ret.push_back((float) s.x());
//        ret.push_back((float) s.y());
//        ret.push_back((float) s.z());
//    }

    return vertex;
}

std::vector<unsigned int> GeoLib::Maillage::getIndice() {
    return indice;
}

size_t GeoLib::Maillage::getVertexBufferSize() const {
    return vertex.size() * sizeof(float) * 3;
}

size_t GeoLib::Maillage::getIndiceBufferSize() const {
    return indice.size() * sizeof(unsigned int);
}
