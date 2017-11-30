//
// Created by julien on 17/10/17.
//

#include "Vector.h"
#include <cmath>
#include <iostream>

vector3 vector3::operator+(const vector3& vec) const {
    return vector3(x + vec.x, y + vec.y, z+ vec.z);
}

//vector3 vector3::operator-(const vector3& vec) {
//    return vector3(x - vec.x, y - vec.y, z - vec.z);
//}

vector3 vector3::operator-(const vector3& vec) const {
    return vector3(x - vec.x, y - vec.y, z - vec.z);
}

vector3 vector3::operator*(float k) const {
    return vector3(x * k, y * k, z * k);
}

vector3 vector3::operator/(float k) const {
    return vector3(x / k, y / k, z / k);
}

bool vector3::operator==(const vector3& vec) const {
    return x == vec.x && y == vec.y && z == vec.z;
}

double vector3::dot(const vector3& vec) const {
    return x*vec.x + y*vec.y + z*vec.z;
}

vector3 vector3::cross(const vector3& vec) const {
    return vector3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}

double vector3::length() const {
    return sqrt(length2());
}

double vector3::length2() const {
    return  x*x + y*y + z*z;
}

vector3 vector3::normalize() const {
    float k = 1 / length();
    return vector3(x * k, y * k, z * k);
}

double vector3::operator[](int i) const {
    if(i > 2)
        std::cout << "vector3 : ATTENTION i > 2" << std::endl;
    if(i == 0)
        return x;
    if(i == 1)
        return y;
    return z;
}

double& vector3::operator[](int i) {
    if(i > 2)
        std::cout << "vector3 : ATTENTION i > 2" << std::endl;
    if(i == 0)
        return x;
    if(i == 1)
        return y;
    return z;
}

std::ostream& operator<<(std::ostream& os, const vector3& vec) {
    os << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    return os;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector2 vector2::operator+(const vector2 & vec) const {
    return vector2(x + vec.x, y + vec.y);
}

vector2 vector2::operator-(const vector2 & vec) const {
    return vector2(x - vec.x, y - vec.y);
}

vector2 vector2::operator*(float k) const {
    return vector2(x * k, y * k);
}

vector2 vector2::operator/(float k) const {
    return vector2(x / k, y / k);
}

bool vector2::operator==(const vector2 & vec) const {
    return x==vec.x && y==vec.y;
}

double& vector2::operator[](int i) {
    if(i > 1)
        std::cout << "vector2 : ATTENTION i > 1" << std::endl;
    if(i == 0)
        return x;
    return y;
}

double vector2::operator[](int i) const {
    if(i > 1)
        std::cout << "vector2 : ATTENTION i > 1" << std::endl;
    if(i == 0)
        return x;
    return y;
}

double vector2::length() const {
    return sqrt(length2());
}

double vector2::length2() const {
    return  x*x + y*y;
}

vector2 vector2::normalize() const {
    float k = 1 / length();
    return vector2(x * k, y * k);
}

std::ostream& operator<<(std::ostream& os, const vector2& vec) {
    os << vec.x << ' ' << vec.y << std::endl;
    return os;
}