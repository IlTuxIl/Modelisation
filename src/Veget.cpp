//
// Created by julien on 16/01/18.
//

#include "Veget.h"


Veget::Veget(const Vector2 &pos, ESPECE_ARBRE type, int _age) : position(pos), espece(type), age(_age){
    developpement = 100.0;
    curCanopee = std::min(age * 0.6 * (developpement/100.0) * maxCanopee, maxCanopee);
    height = std::min(age * 0.6 * (developpement/100.0) * maxHeight, maxHeight);
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
