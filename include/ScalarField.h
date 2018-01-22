//
// Created by julien on 04/12/17.
//

#ifndef MODELISATION_SCALARFIELD_H
#define MODELISATION_SCALARFIELD_H

#include <cmath>
#include <vector>
#include "Image.h"
#include "Array.h"

enum interpolMethod{TRIANGULAIRE, BILINEAIRE, BICUBIQUE};

class ScalarField : public Array {
public:
    ScalarField() = default;
    ScalarField(const Array& a, double defValue = 0.0) ;
    ScalarField(const Vector2& min, const Vector2& max, int _sizeX, int _sizeY, double defValue = 0.0) ;
    ~ScalarField();

    void addValue(int x, int y, double value) {
        values[getIndex(x,y)] += value;;
    }

    void setValue(int x, int y, double value) {
        values[getIndex(x,y)] = value;
    }

    void setValue(int x, double value) {
        values[x] = value;
    }

    double getValue(int x, int y) const {
        return values[getIndex(x,y)];
    }
    double getValue(int x) const {
        return values[x];
    }

    ScalarField normalize() const ;
    ScalarField racineCarre() const ;

    int getSize()const{return values.size();}

    double GradientNorm(int i, int j) const;
    Vector2 Gradient(int i, int j) const;
    Image saveImg(std::string filename);
    void readImg(std::string filename);

    double getHeight(const Vector2& v, interpolMethod method = BILINEAIRE)const;
    double interpolationTriangulaire(const Vector2& v)const;
    double interpolationBilineaire(const Vector2& v)const;
    double interpolationBicubique(const Vector2& v)const;

//    double getMin()const{return valMin; }
//    double getMax()const{return valMax; }

//    void setMin(double v){valMin = v; }
//    void setMax(double v){valMax = v; }

protected:
    std::vector<double> values;
//    double valMin, valMax;

    class Trie{
    public:
        Trie(const ScalarField& _sf):sf(_sf){};
        const ScalarField& sf;
        bool operator()(int a, int b)const { return sf.getValue(a) < sf.getValue(b);}
    };
};


#endif //MODELISATION_SCALARFIELD_H

