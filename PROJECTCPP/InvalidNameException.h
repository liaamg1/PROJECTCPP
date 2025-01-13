#ifndef INVALID_NAME_EXCEPTION_H
#define INVALID_NAME_EXCEPTION_H

#include <exception>
#include <string>
#include <cctype>  // För isalpha()

class InvalidNameException : public std::exception {
public:
    // Återger ett felmeddelande om ogiltigt namn
    const char* what() const noexcept override {
        return "Invalid name! The name cannot be empty or contain invalid characters.";
    }

    // Statisk metod för att validera namn
    static bool isValidName(const std::string& name) {
        for (char c : name) {
            if (!std::isalpha(c) && c != ' ') {  // Tillåter bara bokstäver och mellanslag
                return false;
            }
        }
        return true;
    }
    
};

#endif // INVALID_NAME_HELPER_H
