#include "IntroController.h"
#include "GameManager.h"

IntroController::IntroController(IntroView &v) : view(v)
{}

void IntroController::handleEvent(sf::Event &event) {
    auto mouse_position = sf::Mouse::getPosition(view.getWindow());
    auto translated_pos = view.getWindow().mapPixelToCoords(mouse_position);
    if(view.getRect().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            finished = true;
        }
    }
}