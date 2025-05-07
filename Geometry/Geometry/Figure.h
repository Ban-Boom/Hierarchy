#pragma once
#include <iostream>
#include "FigureCreationException.h"

// ����������� ����� ��� ���� �����
class Figure {
public:
    virtual void print() const = 0;  // ����������� ������� ��� ������ ���������� � ������
    virtual ~Figure() = default;     // ����������� ����������
};
