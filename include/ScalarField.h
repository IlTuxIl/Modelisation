//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_SCALARFIELD_H
#define MODELISATION_SCALARFIELD_H


#include "Array.h"

class ScalarField : public Array {
public:
    ScalarField() = default;
    void saveImg(std::string filename);

protected:
    double* value;
};


#endif //MODELISATION_SCALARFIELD_H

