#pragma once
#include "Triangle.h"

// Класс для прямоугольного треугольника
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C) {
        // Проверка: угол C должен быть равен 90°
        if (C != 90) {
            throw FigureCreationException("угол C не равен 90");
        }
    }

    void print() const override {
        std::cout << "Прямоугольный треугольник (стороны " << a << ", " << b << ", " << c
            << "; углы " << A << ", " << B << ", " << C << ") создан\n";
    }
};
