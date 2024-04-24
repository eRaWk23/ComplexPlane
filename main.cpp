#include <SFML/Graphics.hpp>
#include "complexPlane.h"
#include <iostream>

int main()
{
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width /2;
    unsigned int screenHeight =desktopMode.height / 2;

    //Construct the RenderWindwo
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Complex Plane Visualization");

    //construct the ComplexPlane
    ComplexPlane complexPlane(screenWidth, screenHeight);

    // construct text objects
    sf::Font font;
    font.loadFromFile("");// need to get text file //
    sf::Text text("", font, 16);
    text.setFillColor(sf::Color::White);

    //Loop
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Right)
                {
                    complexPlane.zoomOut();
                    complexPlane.setCenter(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
                else if (event.mouseButton.button == sf::Mouse::Left)
                {
                    complexPlane.zoomIn();
                    complexPlane.setCenter(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                complexPlane.setMouseLocation(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
            }
        }
        //check if escape key was pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        //Update scene
        complexPlane.updateRender();
        complexPlane.loadText(text);

        //draw scene
        window.clear();
        window.draw(complexPlane);
        window.draw(text);
        window.display();
    }
    return 0;
}