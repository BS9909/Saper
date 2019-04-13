#include "MinesweeperController.h"
#include <SFML/Graphics.hpp>
#include <cmath>

MinesweeperController::MinesweeperController(MinesweeperView &v, sf::RenderWindow &win, MSSFMLview &mssfmLview,Minesweeperboard &msb) :view(v),
win(win),
mssfmLview(mssfmLview),
msb(msb)
{}

void MinesweeperController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            msb.revealField(192/event.mouseButton.x, 192/event.mouseButton.y+50); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
        }
        else if (event.mouseButton.button == sf::Mouse::Right)
        {
            msb.toggleFlag(5, 3); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
        }
    }

}
