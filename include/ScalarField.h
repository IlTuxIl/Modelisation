//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_SCALARFIELD_H
#define MODELISATION_SCALARFIELD_H


#include "Array.h"
#include <vector>

enum interpolMethod{TRIANGULAIRE, BILINEAIRE, BICUBIQUE};

class ScalarField : public Array {
public:
    ScalarField() = default;
    ScalarField(const Vector2& min, const Vector2& max, int _sizeX, int _sizeY) ;
    ~ScalarField();

    void addValue(double value) {
        values.push_back(value);
    }

    void setValue(int x, int y, double value) {
        values[getIndex(x,y)] = value;
    }
    double getValue(int x, int y) const {
        return values[getIndex(x,y)];
    }
    double getValue(int x) const {
        return values[x];
    }

    double GradientNorm(int i, int j) const;
    Vector2 Gradient(int i, int j) const;
    void saveImg(std::string filename);
    void readImg(std::string filename);

    double getHeight(const Vector2& v, interpolMethod method = BILINEAIRE)const;
    double interpolationTriangulaire(const Vector2& v)const;
    double interpolationBilineaire(const Vector2& v)const;
    double interpolationBicubique(const Vector2& v)const;

protected:
    std::vector<double> values;
    class Trie{
    public:
        Trie(const ScalarField& _sf):sf(_sf){};
        const ScalarField& sf;
        bool operator()(int a, int b)const { return sf.getValue(a) > sf.getValue(b);}
    };
};


#endif //MODELISATION_SCALARFIELD_H

