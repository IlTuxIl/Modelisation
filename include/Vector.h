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


class Vector2{
public:
    Vector2(double _x = 0, double _y = 0) : x(_x), y(_y){};

    void setX(double val) {x = val;};
    void setY(double val) {y = val;};

    double& getX() {return x;};
    double& getY() {return y;};

    double getX() const{return x;};
    double getY() const{return y;};

    Vector2 operator+(const Vector2&)const;
    Vector2 operator-(const Vector2&)const;
    Vector2 operator*(float)const;
    Vector2 operator/(float)const;
    bool operator==(const Vector2&)const;
    double& operator[](int);
    double operator[](int)const;

    friend std::ostream& operator<< (std::ostream&, const Vector2&);

    double length()const;
    double length2()const;
    Vector2 normalize()const;

private:
    double x,y;
};


/*!\class vector3
 * \brief vector3 = triplet de double
 */
class Vector3{
  public:
    Vector3(Vector2 vec, double _z = 0) : x(vec.getX()), y(vec.getY()), z(_z){};
    Vector3(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z){};

    void setX(double val) {x = val;};
    void setY(double val) {y = val;};
    void setZ(double val) {z = val;};

    double& getX() {return x;};
    double& getY() {return y;};
    double& getZ() {return z;};

    double getX() const{return x;};
    double getY() const{return y;};
    double getZ() const{return z;};

    Vector3 operator+(const Vector3&)const;
    Vector3 operator-(const Vector3&)const;
    Vector3 operator*(float)const;
    Vector3 operator/(float)const;
    bool operator==(const Vector3&)const;
    double operator[](int)const;
    double& operator[](int);

    friend std::ostream& operator<< (std::ostream&, const Vector3&);

    double dot(const Vector3&) const;
    Vector3 cross(const Vector3&) const;
    double length()const;
    double length2()const;
    Vector3 normalize()const;

private:
    double x,y,z;
};

#endif //MODELISATION_VECTOR_H
