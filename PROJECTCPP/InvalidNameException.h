#ifndef INVALID_NAME_EXCEPTION_H
#define INVALID_NAME_EXCEPTION_H

#include <exception>
#include <string>
#include <cctype>  // För isalpha()

class InvalidNameException : public std::exception {
public:
    
    const char* what() const noexcept override {
        return "Invalid name! The name cannot be empty or contain invalid characters.";
    }

    static bool isValidName(const std::string& name) {
        for (char c : name) {
            if (!std::isalpha(c) && c != ' ') {  
                return false;
            }
        }
        return true;
    }
    
};

#endif // INVALID_NAME_HELPER_H
