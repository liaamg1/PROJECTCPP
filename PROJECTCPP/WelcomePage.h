#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <SFML/Graphics.hpp>

class WelcomePage {
public:
    WelcomePage();                          // Konstruktor
    void start();                            // Startar animationen
private:
    sf::RectangleShape rect;                  // Rektangelform för att visa animerad objekt
    sf::Color currentColor;                  // Aktuell färg för rektangeln
    float speedX, speedY;                    // Hastighet i X och Y riktning
    float windowWidth, windowHeight;         // Fönstrets dimensioner
    void moveRectangle(float deltaTime);     // Flytta rektangeln
    void changeColor();                      // Byta färg på rektangeln
};

#endif // WELCOMEPAGE_H
