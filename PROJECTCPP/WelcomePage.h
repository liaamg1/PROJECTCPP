#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class WelcomePage {
public:
    WelcomePage();
    void start();

private:
    void moveRectangle(float deltaTime);
    void changeColor();

    float windowWidth;
    float windowHeight;
    sf::RectangleShape rect;
    sf::Color currentColor;
    float speedX;
    float speedY;

    sf::SoundBuffer collisionSoundBuffer;

    sf::Sound collisionSound;

};

#endif // WELCOMEPAGE_H