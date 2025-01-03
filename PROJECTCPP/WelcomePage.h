#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <SFML/Graphics.hpp>

class WelcomePage {
public:
    WelcomePage();                          // Konstruktor
    void start();                            // Startar animationen
private:
    sf::RectangleShape rect;                  // Rektangelform f�r att visa animerad objekt
    sf::Color currentColor;                  // Aktuell f�rg f�r rektangeln
    float speedX, speedY;                    // Hastighet i X och Y riktning
    float windowWidth, windowHeight;         // F�nstrets dimensioner
    void moveRectangle(float deltaTime);     // Flytta rektangeln
    void changeColor();                      // Byta f�rg p� rektangeln
};

#endif // WELCOMEPAGE_H
