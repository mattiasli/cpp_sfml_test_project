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
        if(handler.getEventManager().getUpIsPressed()) y_pos -= 2.0f;
        if(handler.getEventManager().getDownIsPressed()) y_pos += 2.0f;
        if(handler.getEventManager().getLeftIsPressed()) x_pos -= 2.0f;
        if(handler.getEventManager().getRightIsPressed()) x_pos += 2.0f;
    }

void Game::render()
    {
        renderWindow.clear();

        handler.getMap().render();

        sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(x_pos,y_pos);
        renderWindow.draw(rectangle);

        sf::Texture atlas;
        atlas.loadFromFile("../res/spritesheet.png");
        sf::Sprite sprite(atlas);
        sprite.setTextureRect({0, 0, 16, 16});
        sprite.setScale(4,4);
        sprite.setPosition(50,50);
        renderWindow.draw(sprite);

        renderWindow.display();
    }