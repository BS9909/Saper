#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &v,IntroController &introController,MinesweeperController &minesweeperController,Minesweeperboard &minesweeperboard) : view(v),
introController(introController),
minesweeperController(minesweeperController),
minesweeperboard(minesweeperboard)
{}

void ScoreController::handleEvent(sf::Event &event) {
    auto mouse_position = sf::Mouse::getPosition(view.getWindow());
    auto translated_pos = view.getWindow().mapPixelToCoords(mouse_position);
    if (view.getTextClose().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        view.getWindow().close();
    }
    if (view.getTextPlay().getGlobalBounds().contains(translated_pos)){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            minesweeperboard.newGame();
            introController.setFinished(false);
            minesweeperController.setFinished(false);
        }
    }
}