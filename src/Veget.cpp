//
// Created by julien on 16/01/18.
//

#include "Veget.h"

std::string Veget::getEspece() {

    switch (espece){
        case sapin:
            return "Sapin";
        case pommier:
            return "Pommier";

    }
    return "erreur";
}
