#ifndef INVALID_NAME_EXCEPTION_H
#define INVALID_NAME_EXCEPTION_H

#include <exception>
#include <string>
#include <cctype>  

class InvalidNameException : public std::exception {
public:
    const char* what() const  {
        return "Invalid input! The input cannot be empty or contain invalid characters.";
    }

    static bool isValidName(const std::string& name) {
        for (int i = 0; i < name.length(); ++i) {
            if (!std::isalpha(name[i]) && name[i] != ' ') {
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
        return !number.empty();  
    }
};

#endif // INVALID_NAME_EXCEPTION_H
