#include "WelcomePage.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>  

// Konstruktor för att initiera rektangeln
WelcomePage::WelcomePage() {

    windowWidth = 800.f;
    windowHeight = 600.f;

    rect.setSize(sf::Vector2f(100.f, 100.f));  
    rect.setPosition(windowWidth / 2.f, windowHeight / 2.f); 
    rect.setFillColor(sf::Color::Blue);          

  
    speedX = 300.f;
    speedY = 300.f;
}

void WelcomePage::moveRectangle(float deltaTime) {
    rect.move(speedX * deltaTime, speedY * deltaTime);

  
    if (rect.getPosition().x <= 0.f || rect.getPosition().x + rect.getSize().x >= windowWidth) {
        speedX = -speedX; 
        changeColor();     
    }

    if (rect.getPosition().y <= 0.f || rect.getPosition().y + rect.getSize().y >= windowHeight) {
        speedY = -speedY;  
        changeColor();    
    }
}


void WelcomePage::changeColor() {

    currentColor = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    rect.setFillColor(currentColor); 
}

// START ANIMATION
void WelcomePage::start() {
    
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Välkomstsida med Animation");

    sf::Clock clock;

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        float deltaTime = clock.restart().asSeconds();
        
        moveRectangle(deltaTime);

        window.clear();
        window.draw(rect);
        window.display();
    }
}
