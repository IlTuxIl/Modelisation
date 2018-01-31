//
// Created by julien on 16/01/18.
//

#ifndef MODELISATION_VEGET_H
#define MODELISATION_VEGET_H


#include "Vector.h"

enum ESPECE_ARBRE {pommier, sapin};

class Veget {
public :
    Veget(const Vector2& pos, ESPECE_ARBRE type, int _age);
    Vector2 getPosition() const {return position;}
    int getAge(){ return age;}
    void addAge() {age++;}
    void setAge(int v){age = v;}
    std::string getEspece();

    double getCanopee()const{return curCanopee;}
    double getHeight()const{return height;}
    int getMaturitee()const{return maturite;}
    void computeDeloppement(double slope, double wetness);
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
    Pommier(const Vector2& pos, int age = 0) : Veget(pos, pommier, age), esperanceVie(100), minWetness(0.1), maxWetness(999), maxSlope(0.2f), maxHeight(10.0), maxCanopee(10.0), altitudeMin(0.0), altitudeMax(1000.0), maturite(10){};
};

class Sapin : public Veget{
public :
    Sapin(const Vector2& pos, int age = 0) : Veget(pos, sapin, age), esperanceVie(500), minWetness(0.3), maxWetness(999), maxSlope(0.4f), maxHeight(15.0), altitudeMin(0.0), maxCanopee(7.0), altitudeMax(2000.0), maturite(20){};
};


#endif //MODELISATION_VEGET_H
