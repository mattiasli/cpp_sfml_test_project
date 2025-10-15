#include "../../include/graphics/RenderWindowManager.hpp"
#include "../../include/core/Handler.hpp"

RenderWindowManager::RenderWindowManager(Handler& handler)
: handler(handler),
renderWindow(sf::RenderWindow(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Key Path Walker"))
{
}

sf::RenderWindow& RenderWindowManager::getRenderWindow()
{
    return renderWindow;
}

void RenderWindowManager::setSize(float width, float height)
{
    view.reset(sf::FloatRect(0.f, 0.f, width, height));
    renderWindow.setView(view);
}