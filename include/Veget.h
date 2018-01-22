//
// Created by julien on 16/01/18.
//

#ifndef MODELISATION_VEGET_H
#define MODELISATION_VEGET_H


#include "Vector.h"

enum ESPECE_ARBRE {pommier, sapin};

class Veget {
public :
    Veget(const Vector2& pos, ESPECE_ARBRE type, int age) : position(pos), espece(type), age(0){}
    Vector2 getPosition() const {return position;}
    int getAge(){ return age;}
    void addAge() {age++;}
    void setAge(int v){age = v;}
    std::string getEspece();
protected:
    Vector2 position;
    int age;
    ESPECE_ARBRE espece;
};

class Pommier : public Veget{
public :
    Pommier(const Vector2& pos, int age = 0) : Veget(pos, pommier, age){};

};

class Sapin : public Veget{
public :
    Sapin(const Vector2& pos, int age = 0) : Veget(pos, sapin, age){};
};


#endif //MODELISATION_VEGET_H
