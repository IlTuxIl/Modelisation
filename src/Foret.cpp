//
// Created by julien on 16/01/18.
//

#include "Foret.h"

Foret::Foret(std::vector<Vector2> spawn, const Terrain& t, double angleMax) : array(t.getArray()){
    for(int i = 0; i < spawn.size(); ++i){
        int random = rand() % 100;

        int x,y;
        t.getSlope().getGridIndex(spawn[i], x, y);

        double s = t.getSlope().getValue(x, y);
        double wet = t.getWetness().getValue(x, y);
        if(s >= angleMax)
            random *= 0;
        else
            random *= (1.0-s) * (1.0-s);

//        if(wet < 5.0)
//            random *= 0;
//        else
//            random *=;


        if(random < 10)
            continue;
        else if(random < 80)
            veget.push_back(Sapin(spawn[i]));
        else
            veget.push_back(Pommier(spawn[i]));
    }
}

ScalarField Foret::toScalar() {
    ScalarField ret(array);
    for(int i = 0; i < veget.size(); ++i){
        int x,y;
        ret.getGridIndex(veget[i].getPosition(), x, y);
        ret.addValue(x, y, 1.0);
    }

    return ret;
}
