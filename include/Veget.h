//
// Created by julien on 16/01/18.
//

#ifndef MODELISATION_VEGET_H
#define MODELISATION_VEGET_H


#include "Vector.h"

enum ESPECE_ARBRE {pommier, sapin};

class Veget {
public :
    Veget(const Vector3& pos, ESPECE_ARBRE type) : position(pos), espece(type){}
    Vector3 getPosition(){return position;}
    int getAge(){ return age;}
    void addAge() {age++;}
    void setAge(int v){age = v;}
protected:
    Vector3 position;
    int age;
    ESPECE_ARBRE espece;
};

class Pommier : public Veget{
public :
    Pommier(const Vector3& pos) : Veget(pos, pommier){};
};

class Sapin : public Veget{
public :
    Sapin(const Vector3& pos) : Veget(pos, sapin){};
};


#endif //MODELISATION_VEGET_H
