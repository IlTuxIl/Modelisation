//
// Created by julien on 12/12/17.
//

#include <iostream>
#include <../../include/Noise.h>
#include <../../include/AnalyticHeightField.h>


AnalyticHeightField::AnalyticHeightField(Vector2 min, Vector2 max, int _sizeX, int _sizeY,
                                         std::vector<double> freq, std::vector<double> ampli) : HeightField(min, max, _sizeX, _sizeY){
    Noise n;

    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            double newVal = 0.0;

            for(int k = 0; k < freq.size(); ++k)
                newVal += ampli[k] * (n.AtRidg(getVertex(j,i)/freq[k]));

            values.push_back(newVal);
        }
    }

}
