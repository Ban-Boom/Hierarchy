#pragma once
#include "Triangle.h"

//  ласс дл€ равнобедренного треугольника
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C) {
        // ѕроверка: стороны a и c должны быть равны, углы A и C должны быть равны
        if (a != c || A != C) {
            throw FigureCreationException("стороны a и c или углы A и C не равны");
        }
    }

    void print() const override {
        std::cout << "–авнобедренный треугольник (стороны " << a << ", " << b << ", " << c
            << "; углы " << A << ", " << B << ", " << C << ") создан\n";
    }
};
