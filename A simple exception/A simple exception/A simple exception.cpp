#include <iostream>
#include <string>
#include <exception>

class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "You entered a word of forbidden length!";
    }
};

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw bad_length();
    }
    return str.length();
}

int main() {
    int forbidden_length;
    std::string input;

    std::cout << "Enter the forbidden length: ";
    std::cin >> forbidden_length;
    std::cin.ignore(); 

    while (true) {
        std::cout << "Enter a word: ";
        std::getline(std::cin, input);

        try {
            int length = function(input, forbidden_length);
            std::cout << "The length of the word \"" << input << "\" is " << length << std::endl;
        }
        catch (const bad_length& e) {
            std::cout << e.what() << " Goodbye!" << std::endl;
            break;
        }
    }

    return 0;
}
