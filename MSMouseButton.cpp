//
// Created by Bartek on 07.04.2019.
//

#include "MSMouseButton.h"
#include <SFML/Graphics.hpp>
MSMouseButton::MSMouseButton(MSSFMLview &sfmlview, Minesweeperboard &msb):
sfmlView(sfmlview),
msb(msb)
{

}

void MSMouseButton::controlEvents(sf::RenderWindow &win, sf::Event &event) {
    if(win.pollEvent(event)){
        for (int i = 0; i <msb.getBoardHeight(); ++i) {
            for (int j = 0; j < msb.getBoardWidth(); ++j) {
                auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
                auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
                if(sfmlView.rectangleBox[i].getGlobalBounds().contains(translated_pos)){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                        msb.revealField(i,j);
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
                        msb.toggleFlag(i,j);
                    }
                }
            }
        }
    }
}