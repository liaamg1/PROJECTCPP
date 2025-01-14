#include "WelcomePage.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>  

WelcomePage::WelcomePage() {

    windowWidth = 1500.f;
    windowHeight = 1300.f;

    rect.setSize(sf::Vector2f(200.f, 200.f));
    rect.setPosition(windowWidth / 2.f, windowHeight / 2.f);
    rect.setFillColor(sf::Color::Blue);

    speedX = 700.f;
    speedY = 700.f;

   
    if (!collisionSoundBuffer.loadFromFile("collision.wav")) {
       
    }
    
    collisionSound.setBuffer(collisionSoundBuffer);
   
}

void WelcomePage::moveRectangle(float deltaTime) {
    rect.move(speedX * deltaTime, speedY * deltaTime);



    if (rect.getPosition().x <= 0.f || rect.getPosition().x + rect.getSize().x >= windowWidth) {
        speedX = -speedX;
        changeColor();
        collisionSound.play();
    }

    if (rect.getPosition().y <= 0.f || rect.getPosition().y + rect.getSize().y >= windowHeight) {
        speedY = -speedY;
        changeColor();
        collisionSound.play();
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