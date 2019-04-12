#include "MinesweeperController.h"
#include <SFML/Graphics.hpp>

MinesweeperController::MinesweeperController(MinesweeperView &v, sf::RenderWindow &win, MSSFMLview &mssfmLview,Minesweeperboard &msb) :view(v),
win(win),
mssfmLview(mssfmLview),
msb(msb)
{}

void MinesweeperController::handleEvent(sf::Event &event) {
    if(win.pollEvent(event)) {
        for (int i = 0; i <mssfmLview.getSquareBox().size(); ++i) {
            auto mouse_position = sf::Mouse::getPosition();
            auto translated_pos = mssfmLview.getWindow().mapPixelToCoords(mouse_position);
            if (mssfmLview.getSquareBox()[i].getGlobalBounds().contains(translated_pos)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
                    std::div_t divresult;
                    divresult = std::div(i, msb.getBoardHeight());
                    msb.revealField(i % msb.getBoardHeight(), divresult.quot);
                    view.draw(mssfmLview.getWindow());
                }
            }
        }
    }
}