#include "../include/Game.hpp"

Game::Game()
: window(sf::VideoMode(constants::WindowWidth, constants::WindowHeight), "Key Path Walker"),
eventManager(window)
{
}

void Game::run()
    {
        sf::Clock clock;
        sf::Time deltaTime = sf::Time::Zero;
        while (window.isOpen())
        {
            deltaTime += clock.restart();
            if(deltaTime.asMicroseconds() >= constants::TimePerTick)
            {
                deltaTime = sf::Time::Zero;

                processEvents();
                updateLogic();
                render();
            }
        }
    }

void Game::processEvents()
    {
        eventManager.processEvents();
    }

void Game::updateLogic()
    {
        if(eventManager.getUpIsPressed()) y_pos -= 2.0f;
        if(eventManager.getDownIsPressed()) y_pos += 2.0f;
        if(eventManager.getLeftIsPressed()) x_pos -= 2.0f;
        if(eventManager.getRightIsPressed()) x_pos += 2.0f;
    }

void Game::render()
    {
        sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(x_pos,y_pos);

        window.clear();
        window.draw(rectangle);
        window.display();
    }