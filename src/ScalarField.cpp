//
// Created by julien on 04/12/17.
//

#include <Image.h>
#include "ScalarField.h"

void ScalarField::saveImg(std::string filename) {
    unsigned char* tmp = new unsigned char[sizeX * sizeY];
    for(int i = 0; i < sizeY * sizeX; ++i)
        tmp[i] = (unsigned char)((value[i] / 255.0) * 255);

    Image img(filename, sizeX, sizeY, tmp);
    delete[] tmp;
}
