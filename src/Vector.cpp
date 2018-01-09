//
// Created by julien on 17/10/17.
//

#include <cmath>
#include <iostream>
#include "Vector.h"

Vector3 Vector3::operator+(const Vector3& vec) const {
    return Vector3(x + vec.x, y + vec.y, z+ vec.z);
}

//Vector3 Vector3::operator-(const Vector3& vec) {
//    return Vector3(x - vec.x, y - vec.y, z - vec.z);
//}

Vector3 Vector3::operator-(const Vector3& vec) const {
    return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3 Vector3::operator*(float k) const {
    return Vector3(x * k, y * k, z * k);
}

Vector3 Vector3::operator/(float k) const {
    return Vector3(x / k, y / k, z / k);
}

bool Vector3::operator==(const Vector3& vec) const {
    return x == vec.x && y == vec.y && z == vec.z;
}

double Vector3::dot(const Vector3& vec) const {
    return x*vec.x + y*vec.y + z*vec.z;
}

Vector3 Vector3::cross(const Vector3& vec) const {
    return Vector3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}

double Vector3::length() const {
    return sqrt(length2());
}

double Vector3::length2() const {
    return  x*x + y*y + z*z;
}

Vector3 Vector3::normalize() const {
    float k = 1 / length();
    return Vector3(x * k, y * k, z * k);
}

double Vector3::operator[](int i) const {
    if(i > 2)
        std::cout << "Vector3 : ATTENTION i > 2" << std::endl;
    if(i == 0)
        return x;
    if(i == 1)
        return y;
    return z;
}

double& Vector3::operator[](int i) {
    if(i > 2)
        std::cout << "Vector3 : ATTENTION i > 2" << std::endl;
    if(i == 0)
        return x;
    if(i == 1)
        return y;
    return z;
}

std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
    os << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
    return os;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Vector2 Vector2::operator+(const Vector2 & vec) const {
    return Vector2(x + vec.x, y + vec.y);
}

Vector2 Vector2::operator-(const Vector2 & vec) const {
    return Vector2(x - vec.x, y - vec.y);
}

Vector2 Vector2::operator*(float k) const {
    return Vector2(x * k, y * k);
}

Vector2 Vector2::operator/(float k) const {
    return Vector2(x / k, y / k);
}

bool Vector2::operator==(const Vector2 & vec) const {
    return x==vec.x && y==vec.y;
}

double& Vector2::operator[](int i) {
    if(i > 1)
        std::cout << "Vector2 : ATTENTION i > 1" << std::endl;
    if(i == 0)
        return x;
    return y;
}

double Vector2::operator[](int i) const {
    if(i > 1)
        std::cout << "Vector2 : ATTENTION i > 1" << std::endl;
    if(i == 0)
        return x;
    return y;
}

double Vector2::length() const {
    return sqrt(length2());
}

double Vector2::length2() const {
    return  x*x + y*y;
}

Vector2 Vector2::normalize() const {
    float k = 1 / length();
    return Vector2(x * k, y * k);
}

std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
    os << vec.x << ' ' << vec.y << std::endl;
    return os;
}
