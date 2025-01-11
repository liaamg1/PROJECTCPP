#include "WelcomePage.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>  // F�r rand()

// Konstruktor f�r att initiera rektangeln
WelcomePage::WelcomePage() {
    // Hur stort f�nstret ska vara
    windowWidth = 800.f;
    windowHeight = 600.f;

    rect.setSize(sf::Vector2f(100.f, 100.f));   // Rektangelns storlek
    rect.setPosition(windowWidth / 2.f, windowHeight / 2.f); // Startposition i mitten
    rect.setFillColor(sf::Color::Blue);           // Startf�rg

    // Styr hastighet f�r rektangel
    speedX = 5000.f;
    speedY = 5000.f;
}

// Flytta rektangeln enligt hastigheten och �ndra f�rg n�r den tr�ffar v�ggen
void WelcomePage::moveRectangle(float deltaTime) {
    // Flytta rektangeln baserat p� hastigheten
    rect.move(speedX * deltaTime, speedY * deltaTime);

    // Kolla om rektangeln tr�ffar en v�gg (f�nstrets gr�nser)
    if (rect.getPosition().x <= 0.f || rect.getPosition().x + rect.getSize().x >= windowWidth) {
        speedX = -speedX;  // Byt riktning p� X-hastigheten
        changeColor();     // Byt f�rg n�r den tr�ffar v�ggen
    }

    if (rect.getPosition().y <= 0.f || rect.getPosition().y + rect.getSize().y >= windowHeight) {
        speedY = -speedY;  // Byt riktning p� Y-hastigheten
        changeColor();     // Byt f�rg n�r den tr�ffar v�ggen
    }
}

// Byt f�rg p� rektangeln
void WelcomePage::changeColor() {
    // V�lj en slumpm�ssig f�rg
    currentColor = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    rect.setFillColor(currentColor);  // S�tt den nya f�rgen p� rektangeln
}

// Metod f�r att starta animationen
void WelcomePage::start() {
    // Skapa f�nster f�r animationen
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "V�lkomstsida med Animation");

    sf::Clock clock; //Skapar en klocka

    //Event loop som k�rs s�l�nge f�nstret �r �ppet
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Ber�kna delta-tid
        float deltaTime = clock.restart().asSeconds();
        
        // Kallar p� funktion som har ansvar f�r att flytta rektangel och kolla kollision
        moveRectangle(deltaTime);

        // Rensa f�nstret och rendera rektangeln
        window.clear();
        window.draw(rect);
        window.display();
    }
}
