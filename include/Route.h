#include "HeightField.h"
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
    Index* parent;
    Index position;
    float cout;
    float heuristique;

    Case() : parent(NULL), position(Index(0,0)), cout(INFINITY), heuristique(0) {}
    Case(Index* posParent, Index pos) : parent(posParent), position(pos), cout(INFINITY) {}
};

class Route {
private:
    float cout;
    std::vector<Index> chemin;

public:
    Route(const Vector2& depart, const Vector2& objectif, const HeightField& hf);
    float getCout() const {return cout;}
    const std::vector<Index>& getChemin() const {return chemin;}

private:
    std::vector<Index> getVoisins(const Index& p, int tailleX, int tailleY);
    float calculeCout(const Index& pos_courante,const Index& voisin, const HeightField& hf);
    Index findBest(const std::set<Index>& liste, const std::vector<std::vector<Case>>& t_cases);
};

#endif
