#include <SFML/Graphics.hpp>
#include "../include/EventManager.hpp"
int main()
{
    EventManager eventManager;

    float x_pos = 50, y_pos = 50;
    
    sf::RenderWindow window(sf::VideoMode(800,600), "Key Path Walker");
    sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
    rectangle.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
    eventManager.processEvents(window);

    if(eventManager.getUpIsPressed()) y_pos -= 0.1f;
    if(eventManager.getDownIsPressed()) y_pos += 0.1f;
    if(eventManager.getLeftIsPressed()) x_pos -= 0.1f;
    if(eventManager.getRightIsPressed()) x_pos += 0.1f;
    
    rectangle.setPosition(x_pos,y_pos);
    window.clear();
    window.draw(rectangle);
    window.display();
    }
}