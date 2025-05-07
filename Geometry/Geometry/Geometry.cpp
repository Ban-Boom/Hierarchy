#include <iostream>
#include <stdexcept>
#include <cmath>

class FigureCreationException : public std::domain_error {
public:
    FigureCreationException(const std::string& reason)
        : std::domain_error(reason) {}
};

class Figure {
protected:
    double perimeter;
    double area;

public:
    Figure(double perimeter, double area) : perimeter(perimeter), area(area) {}

    virtual void printInfo() const = 0;
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double angleA, angleB, angleC;

public:
    Triangle(double a, double b, double c, double angleA, double angleB, double angleC)
        : Figure(a + b + c, 0), a(a), b(b), c(c), angleA(angleA), angleB(angleB), angleC(angleC) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw FigureCreationException("Sides must be positive.");
        }
        if (angleA + angleB + angleC != 180) {
            throw FigureCreationException("The sum of angles must be 180.");
        }
    }

    virtual void printInfo() const override {
        std::cout << "Triangle (sides " << a << ", " << b << ", " << c
            << "; angles " << angleA << ", " << angleB << ", " << angleC << ") created" << std::endl;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double angleA, double angleB, double angleC)
        : Triangle(a, b, c, angleA, angleB, angleC) {
        if (angleC != 90) {
            throw FigureCreationException("Angle C must be 90.");
        }
        if (a * a + b * b != c * c) {
            throw FigureCreationException("Sides do not form a right triangle.");
        }
    }

    void printInfo() const override {
        std::cout << "Right triangle (sides " << a << ", " << b << ", " << c
            << "; angles " << angleA << ", " << angleB << ", " << angleC << ") created" << std::endl;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c, double angleA, double angleB, double angleC)
        : Triangle(a, b, c, angleA, angleB, angleC) {
        if (a != c) {
            throw FigureCreationException("Sides a and c must be equal.");
        }
    }

    void printInfo() const override {
        std::cout << "Isosceles triangle (sides " << a << ", " << b << ", " << c
            << "; angles " << angleA << ", " << angleB << ", " << angleC << ") created" << std::endl;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a, double b, double c, double angleA, double angleB, double angleC)
        : Triangle(a, b, c, angleA, angleB, angleC) {
        if (a != b || b != c) {
            throw FigureCreationException("All sides must be equal.");
        }
        if (angleA != 60 || angleB != 60 || angleC != 60) {
            throw FigureCreationException("All angles must be 60.");
        }
    }

    void printInfo() const override {
        std::cout << "Equilateral triangle (sides " << a << ", " << b << ", " << c
            << "; angles " << angleA << ", " << angleB << ", " << angleC << ") created" << std::endl;
    }
};

int main() {
    try {
        RightTriangle rightTriangle(3, 4, 5, 30, 60, 90);
        rightTriangle.printInfo();
    }
    catch (const FigureCreationException& e) {
        std::cout << "Error creating figure. Reason: " << e.what() << std::endl;
    }

    try {
        IsoscelesTriangle isoscelesTriangle(5, 6, 5, 50, 80, 50);
        isoscelesTriangle.printInfo();
    }
    catch (const FigureCreationException& e) {
        std::cout << "Error creating figure. Reason: " << e.what() << std::endl;
    }

    try {
        EquilateralTriangle equilateralTriangle(6, 6, 6, 60, 60, 60);
        equilateralTriangle.printInfo();
    }
    catch (const FigureCreationException& e) {
        std::cout << "Error creating figure. Reason: " << e.what() << std::endl;
    }

    try {
        Triangle invalidTriangle(3, 4, 5, 40, 60, 70);  
        invalidTriangle.printInfo();
    }
    catch (const FigureCreationException& e) {
        std::cout << "Error creating figure. Reason: " << e.what() << std::endl;
    }

    return 0;
}
