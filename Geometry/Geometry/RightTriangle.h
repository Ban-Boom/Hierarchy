#pragma once
#include "Triangle.h"

// ����� ��� �������������� ������������
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C) {
        // ��������: ���� C ������ ���� ����� 90�
        if (C != 90) {
            throw FigureCreationException("���� C �� ����� 90");
        }
    }

    void print() const override {
        std::cout << "������������� ����������� (������� " << a << ", " << b << ", " << c
            << "; ���� " << A << ", " << B << ", " << C << ") ������\n";
    }
};
