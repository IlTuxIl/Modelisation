//
// Created by julien on 16/01/18.
//

#include "Terrain.h"

Terrain::Terrain(const HeightField &h) : height(h){
    slope = height.Slope();
    drainage = height.Drainage();
    wetness = height.Wetness(slope, drainage, 100);
}

Foret Terrain::Vegetation(double canope, int nbIter) const {
        std::vector<Vector2> spawnPossible;
        bool flag;

        for(int i = 0; i < nbIter; ++i){
            flag = true;
            Vector2 tmpPos = height.getRandPos();
            for(int j = 0; j < spawnPossible.size(); ++j) {
                if (Vector2(tmpPos - spawnPossible[j]).length() < canope){
                    flag = false;
                    break;
                }
            }
            if(flag)
                spawnPossible.push_back(tmpPos);
        }

        Foret ret(spawnPossible, *this, 0.8);
        return ret;
}
