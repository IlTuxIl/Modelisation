#include "HeightField.h"
#include "Terrain.h"
#include <set>

#ifndef ROUTE_H
#define ROUTE_H

class Index{
public:
    int x,y;

    Index(int _x, int _y) : x(_x), y(_y) {}
};


class Case {
public:
    Index parent;
    Index position;
    float cout;
    float heuristique;

    Case() : parent(Index(-1,-1)), position(Index(0,0)), cout(INFINITY), heuristique(0) {}
    Case(Index* posParent, Index pos) : parent(Index(-1,-1)), position(pos), cout(INFINITY) {}
};

class Route {
private:
    float cout;
    std::vector<std::vector<Index>> chemin;
    Terrain terrain;
    std::vector<std::vector<Case>> t_cases;

public:
    Route(const Terrain& hf);
    void computeRoute(const Vector2& depart, const Vector2& objectif);

    float getCout() const {return cout;}
    const std::vector<std::vector<Index>>& getChemin() const {return chemin;}
    ScalarField toScalar();
private:
    std::vector<Index> getVoisins(const Index& p, int tailleX, int tailleY);
    float calculeCout(const Index& pos_courante,const Index& voisin);
    Index findBest(const std::set<Index>& liste, const std::vector<std::vector<Case>>& t_cases);
};

#endif
