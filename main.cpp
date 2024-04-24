#include<SFML/Graphics.hpp>
#include"complexPlane.h"
#include<iostream>

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
                if(event.mouseButton.button == sf::Event::Right)
                {
                    complexPlane.zoomOut();
                    complexPlane.setCenter(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
                else if (event.mouseButton.button == sf::Event::MouseLeft)
                {
                    complexPlane.zoomIn();
                    complexPlane.setCenter(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
            }
        }
    }
    return 0;
}