//
// Created by julien on 16/01/18.
//

#include "Veget.h"
#include <iostream>


double lineaire(const double& min, const double& max, const double& val){

    return ((val - min) / (max - min));
}

Veget::Veget(const Vector2 &pos, ESPECE_ARBRE type, int _age, const double &_maxSlope,
             const double &_altitudeMin, const double &_altitudeMax, const double &minWet, const double &maxWet, const double &_maxHeight, const double& h, const double& s, const double& w, const double& _maxCano) : maxCanopee(_maxCano), position(pos), espece(type), age(_age), maxSlope(_maxSlope), minWetness(minWet), maxWetness(maxWet), altitudeMin(_altitudeMin), altitudeMax(_altitudeMax), maxHeight(_maxHeight){

    developpement = 100;

    double deltaAlti = altitudeMax - altitudeMin;
    double midAlti = altitudeMax - (deltaAlti / 2.f);
    double lowAlti = midAlti - (deltaAlti / 3.f);
    double HighAlti = midAlti + (deltaAlti / 3.f);

    double deltaWet = maxWetness - minWetness;
    double midWet = maxWetness - (deltaWet / 2.f);
    double lowWet = midWet - (deltaWet / 3.f);


    if(h < altitudeMin || h > altitudeMax || s > maxSlope || w < minWetness || w > maxWetness)
        developpement = 0;
    else{
        if(h < lowAlti)
            developpement *= 1 - (0.3 * (1 - lineaire(altitudeMin, altitudeMax, h)));
        if(h > HighAlti)
            developpement *= 1 - (0.3 * lineaire(altitudeMin, altitudeMax, h));
        if(w < lowWet)
            developpement *= 1 - (0.3 * lineaire(minWetness, maxWetness, w));
        double tmp = lineaire(0.f, maxSlope, s);
        developpement *= 1.0 - (0.4 * tmp);
    }

    curCanopee = std::min(age * 0.6 * (developpement/100.0) * maxCanopee, maxCanopee);
    height = std::min(age * 0.6 * (developpement/100.0) * maxHeight, maxHeight);
}

Pommier::Pommier(const Vector2 &pos, double hauteur, double slope, double wetness, int age) : Veget(pos, pommier, age, 0.5f, 0.f, 1000.f, 0.05f, 2.f, 10.f, hauteur, slope, wetness, 10.f){
    esperanceVie = 100;
    maturite = 10;
}

Sapin::Sapin(const Vector2 &pos, double hauteur, double slope, double wetness, int age) : Veget(pos, sapin, age, 0.7f, 0.f, 2000.f, 0.1f, 2.f, 60.f, hauteur, slope, wetness, 7.f){
    esperanceVie = 500;
    maturite = 20;
}

bool Veget::simule() {
    age++;

    if(age > esperanceVie/2){
        int deathRng = rand() % 100;
        if(deathRng < 10)
            return false;
    }

    if(developpement <= 10)
        return false;

    height = std::min(age * 0.08 * (developpement/100.0) * maxHeight, maxHeight);
    curCanopee = std::min(age * 0.6 * (developpement/100.0) * maxCanopee, maxCanopee);
    return true;
}

std::vector<Vector2> Veget::reproduction() const {
    std::vector<Vector2> ret;
    if(age > maturite){
        int random = rand() % (developpement/10);

        for(int i = 0; i < random; ++i){
            double p1 = (double) rand() / RAND_MAX;
            double p2 = (double) rand() / RAND_MAX;

            double x = position.getX() + (p1-0.5) * (curCanopee * 50);
            double y = position.getY() + (p2-0.5) * (curCanopee * 50);

            ret.push_back(Vector2(x, y));
        }
    }
    return ret;
}


std::string Veget::getEspece() {

    switch (espece){
        case sapin:
            return "Sapin";
        case pommier:
            return "Pommier";
    }
    return "erreur";
}
