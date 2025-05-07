#pragma once
#include <stdexcept>
#include <string>

// Класс исключения для ошибок создания фигур
class FigureCreationException : public std::domain_error {
public:
    // Конструктор принимает строку с сообщением об ошибке
    FigureCreationException(const std::string& message)
        : std::domain_error(message) {}
};
