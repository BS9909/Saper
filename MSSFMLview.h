//
// Created by Bartek on 02.04.2019.
//

#include <SFML/Graphics.hpp>
#include "Minesweeperboard.h"
#include <iostream>
#ifndef SAPER0_2_MSSFMLVIEW_H
#define SAPER0_2_MSSFMLVIEW_H


class MSSFMLview {
    int squaresize;
    int square_position_x;
    int square_position_y;
    int rows, columns;
    Minesweeperboard &msb;
    GameMode  gameMode;
    sf::RenderWindow &win;
    sf::RenderWindow getWindow();

private:
    std::vector<sf::CircleShape> squareBox;
public:
    const std::vector<sf::CircleShape> getSquareBox() ;

public:
    MSSFMLview(int squarsize,Minesweeperboard &msb,int square_position_x,int square_position_y,sf::RenderWindow &win);
    void eventsController() const;

    void draw();
    void setRows(int newRows){rows=newRows;}
    void setColumns(int newColumns){columns=newColumns;}
    void setGameMode(GameMode newGameMode){gameMode = newGameMode;}
    void setNewParameters(int width, int height, GameMode gameMode);
};


#endif //SAPER0_2_MSSFMLVIEW_H
