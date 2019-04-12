#include "MinesweeperController.h"

MinesweeperController::MinesweeperController(MinesweeperView &v) :view(v)
{}

void MinesweeperController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            finished = true;
        }
    }
}