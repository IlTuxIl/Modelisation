//
// Created by julien on 04/12/17.
//

#include <Image.h>
#include "ScalarField.h"

void ScalarField::saveImg(std::string filename) {
    unsigned char* tmp = new unsigned char[sizeX * sizeY];

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
        }
    }

    Image img(filename, sizeX, sizeY, value);
}
