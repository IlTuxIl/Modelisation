//
// Created by julien on 30/10/17.
//

#include <fstream>
#include <iomanip>
#include <../../include/Maillage.h>

void Maillage::setNbIndiceFace(int v) {
    nbIndicesFace = v;
}

void Maillage::setVertexBuffer(std::vector<float> &p) {
    vertex = p;
}

void Maillage::setIndiceBuffer(const std::vector<unsigned int> &p) {
    indice = p;
}

int Maillage::getNbIndiceFace() const {
    return nbIndicesFace;
}

std::vector<float> Maillage::getVertex() {

//    std::vector<float> ret;
//    ret.reserve(vertex.size() * 3);
//
//    for(Vector3 s : vertex.getVector()){
//        ret.push_back((float) s.x());
//        ret.push_back((float) s.y());
//        ret.push_back((float) s.z());
//    }

    return vertex;
}

std::vector<unsigned int> Maillage::getIndice() {
    return indice;
}

size_t Maillage::getVertexBufferSize() const {
    return vertex.size() * sizeof(float) * 3;
}

size_t Maillage::getIndiceBufferSize() const {
    return indice.size() * sizeof(unsigned int);
}

void Maillage::saveOBJ(std::string filename) {

    std::ofstream fichier(filename);
    fichier << "o Terrain" << std::endl;
    fichier << std::endl;
    for(int i = 0; i < vertex.size(); i += 3){
        fichier << std::fixed << std::setprecision(10) << "v " << vertex[i] << " " << vertex[i+1] << " " << vertex[i+2] << std::endl;
    }
    fichier << std::endl;
    for(int i = 0; i < indice.size(); i += 3){
        fichier << "f " << indice[i]+1 << "// " << indice[i+1]+1 << "// " << indice[i+2]+1 << "//"<< std::endl;
    }
    fichier.close();
}
