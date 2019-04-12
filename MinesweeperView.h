#ifndef UNTITLED2_MINESWEEPERVIEW_H
#define UNTITLED2_MINESWEEPERVIEW_H

#include <SFML/Graphics.hpp>
#include "MSSFMLview.h"

class MinesweeperView {
//    sf::Clock clk;
//    sf::Font font;
//    sf::Text txt;
    MSSFMLview &mssfmLview;
public:
    MinesweeperView(MSSFMLview &mssfmLview);
    void draw(sf::RenderWindow &win);
};




#endif //UNTITLED2_MINESWEEPERVIEW_H
