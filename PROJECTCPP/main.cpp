#include <iostream>
#include "Container.h"
#include "Food.h"
#include "Bulk.h"
#include "SFML/Graphics.hpp"
int main() {

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
    sf::Event e;
    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}
