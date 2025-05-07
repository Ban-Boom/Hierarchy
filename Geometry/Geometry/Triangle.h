#pragma once
#include "Figure.h"

// Базовый класс для треугольников
class Triangle : public Figure {
protected:
    int a, b, c;  // Стороны треугольника
    int A, B, C;  // Углы треугольника

public:
    // Конструктор класса
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {
        // Проверка: сумма углов должна быть равна 180°
        if (A + B + C != 180) {
            throw FigureCreationException("сумма углов не равна 180");
        }
    }

    void print() const override {
        std::cout << "Треугольник (стороны " << a << ", " << b << ", " << c
            << "; углы " << A << ", " << B << ", " << C << ") создан\n";
    }
};
