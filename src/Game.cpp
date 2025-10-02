#include "../include/Game.hpp"

Game::Game()
: renderWindow(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Key Path Walker"),
handler(renderWindow)
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