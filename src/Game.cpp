#include "../include/Game.hpp"

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
    }

void Game::render()
    {
        renderWindow.clear();
        handler.getMap().render();
        renderWindow.display();
    }