#ifndef UNTITLED2_MINESWEEPERVIEW_H
#define UNTITLED2_MINESWEEPERVIEW_H

#include <SFML/Graphics.hpp>

class MinesweeperView {
    sf::Clock clk;
    sf::Font font;
    sf::Text txt;
public:
    void draw(sf::RenderWindow &win);
};




#endif //UNTITLED2_MINESWEEPERVIEW_H
