#pragma once
#include "Triangle.h"

// Класс для равностороннего треугольника
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {}

    void print() const override {
        std::cout << "Равносторонний треугольник (стороны " << a << ", " << b << ", " << c
            << "; углы " << A << ", " << B << ", " << C << ") создан\n";
    }
};
