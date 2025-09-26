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
            deltaTime += clock.restart();
            if(deltaTime.asMicroseconds() >= constants::timePerTick)
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
        handler.getEventManager().processEvents();
    }

void Game::updateLogic()
    {
        if(handler.getEventManager().getUpIsPressed()) y_pos -= 3.5f;
        if(handler.getEventManager().getDownIsPressed()) y_pos += 3.5f;
        if(handler.getEventManager().getLeftIsPressed()) x_pos -= 3.5f;
        if(handler.getEventManager().getRightIsPressed()) x_pos += 3.5f;
    }

void Game::render()
    {
        renderWindow.clear();
        handler.getMap().render();

        handler.getSpriteManager().getPlayerSprite()->setPosition(x_pos,y_pos);
        renderWindow.draw(*handler.getSpriteManager().getPlayerSprite());

        renderWindow.display();
    }