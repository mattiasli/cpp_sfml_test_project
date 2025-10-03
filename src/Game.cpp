#include "../include/Game.hpp"
#include <iostream>

Game::Game()
: handler(),
renderWindow(handler.getRenderWindowManager().getRenderWindow())
{
}

void Game::run()
    {
        sf::Clock clock;
        sf::Time deltaTime = sf::Time::Zero;
        while (renderWindow.isOpen())
        {
            processEvents();
            updateLogic();

            while(deltaTime.asMicroseconds() < constants::timePerTick)
            {
                deltaTime += clock.restart();
            }
            // std::cout << "deltatime: " << deltaTime.asMicroseconds() << std::endl; // TODO, remove
            deltaTime = sf::Time::Zero;

            render();
        }
    }

void Game::processEvents()
    {
        handler.getEventManager().processEvents();
    }

void Game::updateLogic()
    {
        handler.getMap().updateLogic();

        if(handler.getEventManager().GetIsMouseLeftButtonDown()) // TODO, remove
            {
            std::cout << "xgrid: " << handler.getCoordinateConverter().getXGridCoordinate(handler.getEventManager().GetMousePosition().x)
            << "  ygrid: " << handler.getCoordinateConverter().getYGridCoordinate(handler.getEventManager().GetMousePosition().y) << std::endl;
            }
    }

void Game::render()
    {
        renderWindow.clear();
        handler.getMap().render();
        renderWindow.display();
    }