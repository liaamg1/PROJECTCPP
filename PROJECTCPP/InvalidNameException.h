#ifndef INVALID_NAME_EXCEPTION_H
#define INVALID_NAME_EXCEPTION_H

#include <exception>
#include <string>
#include <cctype>  // För isalpha() och isdigit()

class InvalidNameException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid input! The input cannot be empty or contain invalid characters.";
    }

    static bool isValidName(const std::string& name) {
        for (char c : name) {
            if (!std::isalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    static bool isValidNumber(const std::string& number) {
        bool decimalPointFound = false;
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == '.' && !decimalPointFound) {
                decimalPointFound = true;  
            }
            else if (!std::isdigit(number[i])) {
                return false;  
            }
        }
        return !number.empty();  // Returnera false för tomma strängar
    }
};

#endif // INVALID_NAME_EXCEPTION_H
