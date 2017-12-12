//
// Created by julien on 12/12/17.
//

#include <Noise.h>
#include <iostream>
#include "AnalyticHeightField.h"

AnalyticHeightField::AnalyticHeightField(Vector2 min, Vector2 max, int _sizeX, int _sizeY,
                                         std::vector<double> freq, std::vector<double> ampli) {
    Noise n;
    sizeX = _sizeX;
    sizeY = _sizeY;
    values = new double[sizeX * sizeY];
    xyMin = min;
    xyMax = max;
    sizeGridX = (getXMax() - getXMin()) / (sizeX -1);
    sizeGridY = (getYMax() - getYMin()) / (sizeY -1);

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            double newVal = 0.0;

            for(int k = 0; k < freq.size(); ++k)
                newVal += ampli[k] * (n.AtRidg(getVertex(j,i)/freq[k]));

            values[getIndex(j,i)] = newVal;
        }
    }

}
