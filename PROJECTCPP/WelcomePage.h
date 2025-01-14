#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <SFML/Graphics.hpp>

class WelcomePage {
private:
    sf::RectangleShape rect;                  
    sf::Color currentColor;
    float speedX, speedY;                    
    float windowWidth, windowHeight;        
                        
public:
    WelcomePage();                          
    void start();                          
    void moveRectangle(float deltaTime);
    void changeColor();
};

#endif // WELCOMEPAGE_H
