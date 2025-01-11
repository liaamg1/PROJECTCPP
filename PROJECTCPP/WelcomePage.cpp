#include "WelcomePage.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>  // För rand()

// Konstruktor för att initiera rektangeln
WelcomePage::WelcomePage() {
    // Hur stort fönstret ska vara
    windowWidth = 800.f;
    windowHeight = 600.f;

    rect.setSize(sf::Vector2f(100.f, 100.f));   // Rektangelns storlek
    rect.setPosition(windowWidth / 2.f, windowHeight / 2.f); // Startposition i mitten
    rect.setFillColor(sf::Color::Blue);           // Startfärg

    // Styr hastighet för rektangel
    speedX = 5000.f;
    speedY = 5000.f;
}

// Flytta rektangeln enligt hastigheten och ändra färg när den träffar väggen
void WelcomePage::moveRectangle(float deltaTime) {
    // Flytta rektangeln baserat på hastigheten
    rect.move(speedX * deltaTime, speedY * deltaTime);

    // Kolla om rektangeln träffar en vägg (fönstrets gränser)
    if (rect.getPosition().x <= 0.f || rect.getPosition().x + rect.getSize().x >= windowWidth) {
        speedX = -speedX;  // Byt riktning på X-hastigheten
        changeColor();     // Byt färg när den träffar väggen
    }

    if (rect.getPosition().y <= 0.f || rect.getPosition().y + rect.getSize().y >= windowHeight) {
        speedY = -speedY;  // Byt riktning på Y-hastigheten
        changeColor();     // Byt färg när den träffar väggen
    }
}

// Byt färg på rektangeln
void WelcomePage::changeColor() {
    // Välj en slumpmässig färg
    currentColor = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    rect.setFillColor(currentColor);  // Sätt den nya färgen på rektangeln
}

// Metod för att starta animationen
void WelcomePage::start() {
    // Skapa fönster för animationen
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Välkomstsida med Animation");

    sf::Clock clock; //Skapar en klocka

    //Event loop som körs sålänge fönstret är öppet
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Beräkna delta-tid
        float deltaTime = clock.restart().asSeconds();
        
        // Kallar på funktion som har ansvar för att flytta rektangel och kolla kollision
        moveRectangle(deltaTime);

        // Rensa fönstret och rendera rektangeln
        window.clear();
        window.draw(rect);
        window.display();
    }
}
