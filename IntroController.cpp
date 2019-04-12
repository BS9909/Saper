#include "IntroController.h"
#include "GameManager.h"

IntroController::IntroController(IntroView &v) : view(v)
{}

void IntroController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.type == sf::Keyboard::Space) {
            finished = true;
        }
    }
}