//
// Created by julien on 16/01/18.
//

#include "Foret.h"

Foret::Foret(std::string filename, Terrain &t) : array(t.getArray()){
    terrain = &t;
    loadForet(filename);
    computeSpacialisation();
}

Foret::Foret(std::vector<Vector2> spawn, Terrain& t, double angleMax, double minWet, double maxWet) : array(t.getArray()){
    terrain = &t;
    for(int i = 0; i < spawn.size(); ++i){
        int random = rand() % 100;

        int x,y;
        array.getGridIndex(spawn[i], x, y);

        double s = t.getSlope().getValue(x, y);
        double wet = t.getWetness().getValue(x, y);
        double h = t.getHeightMap().getValue(x, y);

        int age = rand() % 500;
        if(random < 10)
            continue;
        else if(random < 70)
            veget.push_back(Sapin(spawn[i], h, s, wet, age));
        else
            veget.push_back(Pommier(spawn[i], h, s, wet, age));
    }
    computeSpacialisation();
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

        int x,y;
        array.getGridIndex(posDenormalise, x, y);
        if(array.checkBound(x, y)) {
            double s = terrain->getSlope().getValue(x, y);
            double wet = terrain->getWetness().getValue(x, y);
            double h = terrain->getHeightMap().getValue(x, y);

            if (espece == "Sapin")
                veget.push_back(Sapin(posDenormalise, h, s, wet, age));
            else if (espece == "Pommier")
                veget.push_back(Pommier(posDenormalise, h, s, wet, age));
        }
    }

    fichier.close();
}

ScalarField Foret::toScalar() {
    ScalarField ret(array);
    for(int i = 0; i < veget.size(); ++i){
        int x,y;
        ret.getGridIndex(veget[i].getPosition(), x, y);
        if(array.checkBound(x, y))
            ret.addValue(x, y, 1.0);
    }

    return ret;
}

void Foret::computeSpacialisation() {
    densiteVeget.resize(array.getSizeX() * array.getSizeY());

    for(int i = 0; i < veget.size(); ++i){
        int x,y;
        array.getGridIndex(veget[i].getPosition(), x, y);
        if(array.checkBound(x, y))
            densiteVeget[x + array.getSizeX() * y].push_back(veget[i]);
    }
}

void Foret::simule() {
    std::vector<Veget> tmp;
    int nbMort = 0;
    int nbNaissance = 0;
    std::cout << "nbArbre Avant Simule : " << veget.size()<< std::endl;
    tmp.reserve(veget.size());

    int cpt = 0;
    for(Veget v : veget) {
        cpt++;
        int posVX, posVY;
        array.getGridIndex(v.getPosition(), posVX, posVY);

        if(array.checkBound(posVX, posVY)) {
            if (v.simule() && checkCanopee(posVX, posVY, v.getPosition())) {
                tmp.push_back(v);

                for (Vector2 newTree : v.reproduction()) {
                    int x, y;
                    array.getGridIndex(newTree, x, y);
                    bool flag = checkCanopee(x, y, newTree);

                    if (flag && array.checkBound(x, y)) {

                        double s = terrain->getSlope().getValue(x, y);
                        double wet = terrain->getWetness().getValue(x, y);
                        double h = terrain->getHeightMap().getValue(x, y);

                        if (v.getEspece() == "Sapin") {
                            Veget tree = Sapin(newTree, h, s, wet, 1);
                            if (tree.simule()) {
                                tmp.push_back(tree);
                                addSpacialisation(x, y, tmp[tmp.size() - 1]);
                                ++nbNaissance;
                            }
                        } else if (v.getEspece() == "Pommier") {
                            Veget tree = Pommier(newTree, h, s, wet, 1);
                            if (tree.simule()) {
                                tmp.push_back(Pommier(newTree, h, s, wet, 0));
                                addSpacialisation(x, y, tmp[tmp.size() - 1]);
                                ++nbNaissance;
                            }
                        }

                    }
                }
            } else {
                ++nbMort;

                if (array.checkBound(posVX, posVY)) {
                    for (int i = 0; i < densiteVeget[posVX + array.getSizeX() * posVY].size(); ++i) {
                        if (densiteVeget[posVX + array.getSizeX() * posVY][i].getPosition() == v.getPosition()) {
                            delSpacialisation(posVX, posVY, i);
                            break;
                        }
                    }
                }

            }
        }
    }
    veget = tmp;
    std::cout << "nbArbre Apres Simule : " << veget.size() << " nbMorts : " << nbMort << " nbNaissances : " << nbNaissance << std::endl;
}

bool Foret::checkCanopee(int x, int y, Vector2 pos) const {

    bool flag = true;

    for(int tmpY = y-1; tmpY < y+1; ++tmpY){
        for(int tmpX = x-1; tmpX < x+1; ++tmpX){

            if(!flag)
                break;
            if(array.checkBound(tmpX, tmpY)) {
                for (int i = 0; i < densiteVeget[tmpX + array.getSizeX() * tmpY].size(); ++i) {
                    Veget tmpVeget = densiteVeget[tmpX + array.getSizeX() * tmpY][i];
                    if (Vector2(pos - tmpVeget.getPosition()).length() < tmpVeget.getCanopee() * 3 && !(tmpVeget.getPosition() == pos)) {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }

    return flag;
}

Maillage Foret::toMaillage() const {
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
        vertex.push_back(z + (float) veget[i].getHeight());

//        std::cout << veget[i].getHeight() << std::endl;
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

void Foret::addSpacialisation(int x, int y, const Veget& v) {
    densiteVeget[x + array.getSizeX() * y].push_back(v);
}

void swap(std::vector<Veget>& tab, int a, int b){
    if(a != b){
        Veget tmp = tab[a];
        tab[a] = tab[b];
        tab[b] = tmp;
    }
}

void Foret::delSpacialisation(int x, int y, int id) {
    swap(densiteVeget[x + array.getSizeX() * y], id, densiteVeget[x + array.getSizeX() * y].size() - 1);
    densiteVeget[x + array.getSizeX() * y].pop_back();
}
