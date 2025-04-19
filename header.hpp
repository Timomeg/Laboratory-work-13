#pragma once
#include <iostream>
#include <stdexcept>
class GeometryProgression{
    int first_elem;
    int znam;
    size_t size;
    int* arr;
public:
    GeometryProgression(int first_elem, int znam, size_t size, int *arr);
    void print() const;

};
class GeometryException: public std::invalid_argument{
    GeometryProgression gp;
public:
    GeometryException(std::string msg, GeometryProgression& gp1);
    void print() const;
};