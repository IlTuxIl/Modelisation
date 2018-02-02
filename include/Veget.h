//
// Created by julien on 16/01/18.
//

#ifndef MODELISATION_VEGET_H
#define MODELISATION_VEGET_H


#include "Vector.h"
#include <vector>

enum ESPECE_ARBRE {pommier, sapin};

class Veget {
public :
    Veget(const Vector2& pos, ESPECE_ARBRE type, int _age, const double& maxSlope,
          const double& altitudeMin, const double& altitudeMax, const double& minWet,
          const double& maxWet, const double& _maxHeight, const double& h, const double& s, const double& w, const double& maxCanopee);
    Vector2 getPosition() const {return position;}
    int getAge(){ return age;}
    void addAge() {age++;}
    void setAge(int v){age = v;}
    std::string getEspece();

    double getCanopee()const{return curCanopee;}
    double getHeight()const{return height;}
    int getMaturitee()const{return maturite;}
    bool simule();
    std::vector<Vector2> reproduction() const;

protected:
    Vector2 position;
    int age;
    int esperanceVie;
    double curCanopee;
    int developpement;
    double minWetness, maxWetness, maxSlope, altitudeMin, altitudeMax, maxHeight, maxCanopee;
    int maturite;
    double height;
    ESPECE_ARBRE espece;
};

class Pommier : public Veget{
public :
    Pommier(const Vector2& pos, double hauteur, double slope, double wetness, int age = 0);
};

class Sapin : public Veget {
public :
    Sapin(const Vector2 &pos, double hauteur, double slope, double wetness, int age = 0);
};


#endif //MODELISATION_VEGET_H
