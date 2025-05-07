#pragma once
#include "Triangle.h"

// ����� ��� ��������������� ������������
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C) {
        // ��������: ������� a � c ������ ���� �����, ���� A � C ������ ���� �����
        if (a != c || A != C) {
            throw FigureCreationException("������� a � c ��� ���� A � C �� �����");
        }
    }

    void print() const override {
        std::cout << "�������������� ����������� (������� " << a << ", " << b << ", " << c
            << "; ���� " << A << ", " << B << ", " << C << ") ������\n";
    }
};
