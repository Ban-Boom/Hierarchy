#pragma once
#include <iostream>
#include "FigureCreationException.h"

// Абстрактный класс для всех фигур
class Figure {
public:
    virtual void print() const = 0;  // Виртуальная функция для вывода информации о фигуре
    virtual ~Figure() = default;     // Виртуальный деструктор
};
