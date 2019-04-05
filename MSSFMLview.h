//
// Created by Bartek on 02.04.2019.
//

#include <SFML/Graphics.hpp>
#include "Minesweeperboard.h"
#ifndef SAPER0_2_MSSFMLVIEW_H
#define SAPER0_2_MSSFMLVIEW_H


class MSSFMLview {
    int squaresize;
    int square_position_x;
    int square_position_y;
    Minesweeperboard &msb;
public:
    MSSFMLview(int squarsize,Minesweeperboard &msb,int square_position_x,int square_position_y);
    void draw(sf::RenderWindow &win);
};


#endif //SAPER0_2_MSSFMLVIEW_H
