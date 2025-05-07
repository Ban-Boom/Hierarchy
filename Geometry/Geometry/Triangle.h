#pragma once
#include "Figure.h"

// ������� ����� ��� �������������
class Triangle : public Figure {
protected:
    int a, b, c;  // ������� ������������
    int A, B, C;  // ���� ������������

public:
    // ����������� ������
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {
        // ��������: ����� ����� ������ ���� ����� 180�
        if (A + B + C != 180) {
            throw FigureCreationException("����� ����� �� ����� 180");
        }
    }

    void print() const override {
        std::cout << "����������� (������� " << a << ", " << b << ", " << c
            << "; ���� " << A << ", " << B << ", " << C << ") ������\n";
    }
};
