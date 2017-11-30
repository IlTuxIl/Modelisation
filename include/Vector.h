//
// Created by julien on 30/11/17.
//

#ifndef MODELISATION_VECTOR_H
#define MODELISATION_VECTOR_H

/*!
 * \file Vector.h
 * \brief vector et index
 * \author FLECKINGER Julien
 */
#include <ostream>

/*!\class vector3
 * \brief vector3 = triplet de double
 */
class vector3{
  public:
    vector3(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z){};

    double& getX() {return x;};
    double& getY() {return y;};
    double& getZ() {return z;};

    double getX() const{return x;};
    double getY() const{return y;};
    double getZ() const{return z;};

    vector3 operator+(const vector3&)const;
    vector3 operator-(const vector3&)const;
    vector3 operator*(float)const;
    vector3 operator/(float)const;
    bool operator==(const vector3&)const;
    double operator[](int)const;
    double& operator[](int);

    friend std::ostream& operator<< (std::ostream&, const vector3&);

    double dot(const vector3&) const;
    vector3 cross(const vector3&) const;
    double length()const;
    double length2()const;
    vector3 normalize()const;

private:
    double x,y,z;
};

class vector2{
  public:
    vector2(double _x = 0, double _y = 0) : x(_x), y(_y){};

    double& getX() {return x;};
    double& getY() {return y;};

    double getX() const{return x;};
    double getY() const{return y;};

    vector2 operator+(const vector2&)const;
    vector2 operator-(const vector2&)const;
    vector2 operator*(float)const;
    vector2 operator/(float)const;
    bool operator==(const vector2&)const;
    double& operator[](int);
    double operator[](int)const;

    friend std::ostream& operator<< (std::ostream&, const vector2&);

    double length()const;
    double length2()const;
    vector2 normalize()const;

  private:
    double x,y;
};

#endif //MODELISATION_VECTOR_H