//
// Created by julien on 16/01/18.
//

#include "Foret.h"

Foret::Foret(std::string filename, Terrain &t) : array(t.getArray()){
    terrain = &t;
    loadForet(filename);
}

Foret::Foret(std::vector<Vector2> spawn, Terrain& t, double angleMax, double minWet, double maxWet) : array(t.getArray()){
    terrain = &t;
    for(int i = 0; i < spawn.size(); ++i){
        int random = rand() % 100;

        int x,y;
        t.getSlope().getGridIndex(spawn[i], x, y);

        double s = t.getSlope().getValue(x, y);
        double wet = t.getWetness().getValue(x, y);

        if(s >= angleMax)
            random *= 0;
        else
            random *= (1.0-s) * (1.0-s);

        if(wet < minWet)
            random *= 0;
        else if(wet < maxWet) {
            double tmp = (wet - minWet) / (maxWet - minWet);
            random *= (1.0 - tmp) * (1.0 - tmp);

        }
        int age = rand() % 100;
        if(random < 10)
            continue;
        else if(random < 80)
            veget.push_back(Sapin(spawn[i], age));
        else
            veget.push_back(Pommier(spawn[i], age));
    }
}

void Foret::saveForet(std::string filename) const {
    std::ofstream fichier(filename, std::ios::binary);
    if(!fichier.is_open())
    {
        std::cout << "Impossible d'ouvrir le fichier en ecriture !" << std::endl;
    }

    fichier << veget.size() << std::endl;

    for(Veget v : veget){

        Vector2 posNormalise = v.getPosition();
        posNormalise.setX((posNormalise.getX() - array.getXMin()) / (array.getXMax() - array.getXMin()));
        posNormalise.setY((posNormalise.getY() - array.getYMin()) / (array.getYMax() - array.getYMin()));

        fichier << posNormalise.getX() << " " << posNormalise.getY() << " " << v.getAge() << " " << v.getEspece() << std::endl;
    }

    fichier.close();
}

void Foret::loadForet(std::string filename) {
    std::ifstream fichier(filename, std::ios::out | std::ios::binary);
    if(!fichier.is_open())
    {
        std::cout << "Impossible d'ouvrir le fichier en lecture !" << std::endl;
    }

    int nbArbre;
    fichier >> nbArbre;

    veget.reserve(nbArbre);

    double x,y;
    int age;
    std::string espece;

    for(int i = 0; i < nbArbre; ++i){
        fichier >> x >> y >> age >> espece;

        x = (array.getXMin() + x) * (array.getXMax() - array.getXMin());
        y = (array.getXMin() + y) * (array.getYMax() - array.getYMin());

        Vector2 posDenormalise = Vector2(x, y);

        if(espece == "Sapin")
            veget.push_back(Sapin(posDenormalise, age));
        else if(espece == "Pommier")
            veget.push_back(Pommier(posDenormalise, age));
    }

    fichier.close();
}

ScalarField Foret::toScalar() {
    ScalarField ret(array);
    for(int i = 0; i < veget.size(); ++i){
        int x,y;
        ret.getGridIndex(veget[i].getPosition(), x, y);
        ret.addValue(x, y, 1.0);
    }

    return ret;
}

//TODO
void Foret::simule() {

    for(Veget v : veget){
        v.addAge();
    }

}

Maillage Foret::toMaillage(float hauteur) const {
    Maillage ret;
    std::vector<float> vertex;
    std::vector<unsigned int> face;

    for(int i = 0; i < veget.size(); ++i){

        float x = (float) veget[i].getPosition().getX();
        float y = (float) veget[i].getPosition().getY();
        float z = (float) terrain->getHeightMap().getHeight(veget[i].getPosition());

        vertex.push_back(x);
        vertex.push_back(y);
        vertex.push_back(z);

        vertex.push_back(x);
        vertex.push_back(y);
        vertex.push_back(z + hauteur);
    }

    for(int i = 0; i < veget.size()*2; i+=2){
        face.push_back(i);
        face.push_back(i+1);
    }

    ret.setNbIndiceFace(2);
    ret.setVertexBuffer(vertex);
    ret.setIndiceBuffer(face);
    return ret;
}
